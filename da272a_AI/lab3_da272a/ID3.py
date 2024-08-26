import pandas as pd
import numpy as np
import math 

class Utils:
    @staticmethod
    def entropy(target_column):
        num_instances_all_classes = len(target_column)
        value_counts = target_column.value_counts()
        entropy = 0  
        for target_value in value_counts.keys():         
            num_instances_current_class = value_counts[target_value]
            share_instances_current_class = num_instances_current_class / num_instances_all_classes   
            entropy = entropy - share_instances_current_class * math.log2(share_instances_current_class)
        return entropy
    
    @staticmethod
    def find_dominating_class(target_column):
        return_class = None
        count_return_class = 0
        value_counts = target_column.value_counts()
        for target_value in value_counts.keys():
            if value_counts[target_value] > count_return_class:
                count_return_class = value_counts[target_value] 
                return_class = target_value        
        return return_class
    
    @staticmethod
    def get_next_node_id():
        global node_id_counter
        node_id = node_id_counter
        node_id_counter = node_id_counter + 1
        return node_id
        
    @staticmethod
    def reset_node_id_counter():
        global node_id_counter
        node_id_counter = 1


class Node:
    def __init__(self, height, max_height, input_columns, target_column, parent, parent_split_value):
        self.height = height
        self.max_height = max_height
        self.input_columns = input_columns
        self.target_column = target_column
        self.split_variable = None
        self.input_names = self.input_columns.keys()
        self.target_name = self.target_column.keys()[0]
        self.parent = parent
        self.class_name = None
        self.id = Utils.get_next_node_id()
        self.children = {}
        
    def split(self):
        if self.height == self.max_height or self.target_column[self.target_name].nunique() == 1:
            self.class_name = Utils.find_dominating_class(self.target_column)
            return
        
        max_info_gain = -1
        best_feature = None
        best_child_nodes = None

        for feature in self.input_names:
            info_gain, child_nodes = self.calculate_info_gain(feature)
            if info_gain > max_info_gain:
                max_info_gain = info_gain
                best_feature = feature
                best_child_nodes = child_nodes
        
        self.split_variable = best_feature
        
        for value, child_node_data in best_child_nodes.items():
            child_node = Node(self.height + 1, self.max_height, child_node_data['input_columns'],
                              child_node_data['target_column'], self, value)
            child_node.split()
            self.children[value] = child_node
    
    def calculate_info_gain(self, feature):
        current_entropy = Utils.entropy(self.target_column)
        total_entropy = 0
        child_nodes = {}
        
        for value in self.input_columns[feature].unique():
            subset = self.input_columns[self.input_columns[feature] == value]
            subset_target = self.target_column.loc[subset.index]
            subset_entropy = Utils.entropy(subset_target)
            weighted_entropy = (len(subset) / len(self.input_columns)) * subset_entropy
            total_entropy += weighted_entropy
            child_nodes[value] = {'input_columns': subset, 'target_column': subset_target}
        
        info_gain = current_entropy - total_entropy
        
        return info_gain, child_nodes
    
    def print(self):
        print("Node<" + str(self.id) + ">" )
        
        if not self.children:
            # Ensure self.class_name is a string
            class_name = str(self.class_name) if isinstance(self.class_name, tuple) else self.class_name
            print("  Leaf node - Parent: " + str(self.parent.id) + ", Decision: " + class_name)
        else:
            if self.parent is None:
                print("  Non leaf node - Parent: None")
            else:
                print("  Non leaf node - Parent: " + str(self.parent.id))    
            print("  Split variable: " + self.split_variable)
                
            for child_split_value in self.children.keys():
                child_node = self.children[child_split_value]  
                print("    Child_node: " + str(child_node.id) + ", split_value: " + str(child_split_value))


class DecisionTree:
    def __init__(self, max_height, instances, target_name):
        Utils.reset_node_id_counter()
        self.max_height = max_height;
        self.target_column = instances[[target_name]]
        if self.target_column[target_name].unique().size != 2:
            print("Error: Only binary target variables are supported")
            exit()
        self.input_columns = instances.drop([target_name], axis=1) 
        node_id_counter = 1
        self.root = Node(1, self.max_height, self.input_columns, self.target_column, None, None)
        self.generate()
    
    def generate(self):
        self.root.split()
    
    def print_tree(self):
        if self.root is None:
            print("Decision tree is empty")
            return
        
        node_queue = []
        node_queue.append(self.root)
        
        while node_queue:
            current_node = node_queue.pop(0)
            current_node.print()
            
            for child_node in current_node.children.values():
                node_queue.append(child_node)


def main():
    golf_dataframe = pd.read_csv("golf_dataset.csv")
    print(golf_dataframe)
    print("\n")
    max_height = 3
    dt = DecisionTree(max_height, golf_dataframe, 'Play Golf')
    dt.print_tree()

main()
