#ifndef HASH
#define HASH

#define HASH_TABLE_SIZE  256

typedef char* 			datatype;		/* data type */	
typedef unsigned char 		HashTableIndex;         /* index into hash table */

typedef struct Node
{
        struct node* next; 	/* next node */
        datatype data;		/* loop name */
	int address;		/* adress of loop */
} Node;

typedef struct Node*           HashTableType;		/* hash table type */

int 			compare			(datatype data_1, datatype data_2);		/* compare two datatype elemetnts */
HashTableIndex 		hash_it			(datatype str);					/* return hash function value */
Node* 			create_Node		(datatype data, int address, HashTableType* hashTable);	/* insert node at the begining of the list */
int 			delete_Node		(datatype data, HashTableType* hashTable);	/* delete node with data */
Node* 			find_Node		(datatype data, HashTableType* hashTable);	/* find Node with data */
HashTableType* 		create_HashTable	(HashTableType* NewHashTable);			/* create hashtable */
int 			delete_HashTable	(HashTableType* HashTable);			/* delete hashtable */

#endif
