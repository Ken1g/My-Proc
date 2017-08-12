#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "compile_func.h"

int compare(datatype data_1, datatype data_2) 	/* if datatype changes from char* to smth this function have to be changed in a correct way */
{
	int i;
	
	if (strlen(data_1) != strlen(data_2))
		return 0;
	else
	{
		for (i = 0; i < strlen(data_1); i++)
		{
			if (data_1[i] != data_2[i])
				return 0;
		}
	}
	return 1;
}

HashTableIndex hash_it(datatype str) 
{
	HashTableIndex h = 0;
	
	while (*str) 
		h += *str++;
   	return h;
}

HashTableType* create_HashTable(HashTableType* NewHashTable)
{
	NewHashTable = malloc(HASH_TABLE_SIZE * sizeof(HashTableType));
	return(NewHashTable);
}

int delete_HashTable(HashTableType* HashTable)
{
	int i;
	Node *n1, *n2;

	for (i = 0; i < 256; i++)
	{
		if (HashTable[i])
		{
			n1 = HashTable[i];
			while (n1)
			{
				n2 = (Node*) n1->next;
				free(n1);
				free(n1->data);
				n1 = n2;
			}
		}
	}
	free(HashTable);
	return 0;
}

Node* create_Node(datatype data, int adress, HashTableType* hashTable) 	
{
	HashTableIndex index;
	Node* next_Node = NULL;
	Node* new_Node = NULL;

	index = hash_it(data);
	new_Node = malloc(sizeof(Node));
	next_Node = hashTable[index];
	hashTable[index] = new_Node;
	new_Node->next = next_Node;
	new_Node->data = malloc(sizeof(datatype) * MAX_LOOP_NAME_LENGTH);
	strcpy(new_Node->data, data);
	new_Node->adress = adress;
    	return new_Node;
}

int delete_Node(datatype data, HashTableType* hashTable) 		
{
	Node* next_Node = NULL;
	Node* this_Node = NULL;
	HashTableIndex index;

	index = hash_it(data);
	this_Node = hashTable[index];
	while (this_Node && !compare(this_Node->data, data)) 
	{
		next_Node = this_Node;
		this_Node = (Node*)this_Node->next;
    	}
	if (!this_Node) 
		return 1;
	if (next_Node)
     		next_Node->next = this_Node->next;
	else
		hashTable[index] = (Node*)this_Node->next;
	free(this_Node);
	free(this_Node->data);
	return 0;
}

Node* find_Node(datatype data, HashTableType* hashTable) 	
{
	Node* this_Node = NULL;
	
	this_Node = hashTable[hash_it(data)];
	while (this_Node && !compare(this_Node->data, data)) 
		this_Node = (Node*)this_Node->next;
	if (this_Node)	
		return this_Node;
	else
		return NULL;
} 
