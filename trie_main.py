#!/usr/bin/env python3

'''
Spring 2018 Data Structures Final Project
Yejee Oh (yoh1), Olivia Wang (owang1)
Trie Implementation
'''

# IMPORTS

class Node(object):
    
    def __init__(N, char: str):
        N.value = char
        N.children = []
        N.end_word = False

# INSERT FUNCTION

def insert(root, word: str):

     # Set node equal to root
    node = root

    # Iterate through given word
    for c in word:

        # Keep track of whether or not character is found in children
        in_children = False

        # Set in_children to false if c is not in children nodes
        for child in node.children:

            # If character is in children, point node to child
            if child.value == c:
                node = child
                in_children = True
                break

        # If character is NOT in children, add a new child
        if not in_children:
            next_node = Node(c)
            node.children.append(next_node)
            node = next_node

    # Mark last character as leaf node
    node.end_word = True

# SEARCH FUNCTION

def search(root, word: str):

    # Set node equal to root
    node = root

    # Check if root has no children
    if not root.children:
        return False

    # Iterate through given word
    for c in word:

        # Keep track of whether or not character is found
        in_children = False

        for child in node.children:

            # If character is found in existing child, set char_found to True
            if child.value == c:
                in_children = True
                node = child
                break

        # If character is not found, return False
        if not in_children:
            return False

    # If not return before, the word has been found; return True
    if node.end_word:
        return True
    else:
        return False

# MAIN

if __name__ == "__main__":
    root = Node('*')
    insert(root, "hackathon")
    insert(root, 'hack')

    print(search(root, 'hac'))
    print(search(root, 'hack'))
    print(search(root, 'hackathon'))
    print(search(root, 'ha'))
    print(search(root, 'hammer'))