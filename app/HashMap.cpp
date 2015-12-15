#include <iostream>
#include <string>
#include "HashMap.hpp"
namespace
{

	const double loadFactorLimit = 0.80;

	unsigned int calculateBucketSize(int buckets)
	{
		return ((buckets * 2) + 1);
	}

	unsigned int hash_function(const std::string& word)
	{
		int hash = 0;
		int letter;
		for(char k: word)
		{
			letter = (int) k;
			hash = hash + letter;
		}
		return hash;
	}

	unsigned int get_index(int hashvalue, int buckets)
	{
		return hashvalue % buckets;
	}

}

HashMap::HashMap()
	: sz{0}, numBuckets(initialBucketCount), array{new Node*[bucketCount()]}, hasher{hash_function}
	{
		for(int i = 0; i < bucketCount(); i++)
		{
			array[i] = nullptr;
		}
	}

HashMap::HashMap(HashFunction hasher)
	: sz{0}, numBuckets(initialBucketCount), array{new Node*[bucketCount()]}, hasher{hasher}
{
	for(int i = 0; i < bucketCount(); i++)
	{
		array[i] = nullptr;
	}
}

HashMap::HashMap(const HashMap& hm)
	: sz{hm.sz}, numBuckets(hm.numBuckets), array{new Node*[hm.numBuckets]}, hasher{hm.hasher}
{
	for(int i = 0; i < bucketCount(); i++)
	{
		array[i] = nullptr;
	}

	arrayCopy(array, hm.array, size());
}

HashMap::~HashMap()
{
	for(int i = 0; i < bucketCount(); i++)
	{
		Node* current = array[i];
		Node* deleteNode;
		while(current != nullptr)
		{
			if(current != nullptr)
			{
				deleteNode = current;
				current = current -> next;
				delete deleteNode;
			}
		}
	}
	delete[] array;	
}

HashMap& HashMap::operator = (const HashMap& hm)
{
	if((this == &hm) == false)
	{
		array = new Node*[bucketCount()];
		for(int i = 0; i < bucketCount(); i++)
		{
			array[i] = nullptr;
		}	
		arrayCopy(array, hm.array, size());
	}
	return *this;
}

void HashMap::arrayCopy(Node** target, Node** source, unsigned int size)
{
	for(int i = 0; i < size; i++)
	{
		Node* head = source[i];
		Node* thead = target[i];
		while(head != nullptr)
		{
			Node* target = new Node;
			target -> key = head -> key;
			target -> value = head -> value;
			thead = target;
			thead = thead -> next;
			head = head -> next;
		}			
	}
}

void HashMap::add(const std::string& key, const std::string& value)
{
	int HashValue = hasher(key);
	int index = get_index(HashValue, bucketCount());
	if(contains(key) == false)
	{
		sz += 1;
		Node* newPair = new Node;
		newPair -> key = key;
		newPair -> value = value;
		newPair -> next = array[index];
		array[index] = newPair;

		if(loadFactor() > loadFactorLimit)
		{

			int newBucketSize = calculateBucketSize(numBuckets);
			Node** newArray = new Node*[newBucketSize];
			for(int i = 0; i < newBucketSize; i++)
			{
				newArray[i] = nullptr;
			}

			for(int i = 0; i < bucketCount(); i++)
			{
				Node* temp = array[i];
				while((temp == nullptr) == false)
				{
					index = get_index(hasher(temp -> key), newBucketSize);
					Node* newNode = new Node;
					newNode -> key = temp -> key;
					newNode -> value = temp -> value;
					newNode -> next = newArray[index];
					newArray[index] = newNode;
					temp = temp -> next;
				}
			}
		array = newArray;
		numBuckets = newBucketSize;
		}
	}
}

void HashMap::remove(const std::string& key)
{
	if(contains(key) == true)
	{
		sz -= 1;
		int HashValue = hasher(key);
		int index = get_index(HashValue, bucketCount());
		Node* temp;
		Node* prev;

		if(array[index] -> key != key)
		{
			temp = array[index];

			while(temp != nullptr)
			{
				prev = temp;
				temp = temp -> next;
			}
			prev -> next = temp -> next;
			delete temp;
		}

		else
		{
			temp = array[index] -> next;
			delete array[index];
			array[index] = temp;
		}
	}
}

bool HashMap::contains(const std::string& key) const
{
	int HashValue = hasher(key);
	int index = get_index(HashValue, bucketCount());
	Node* current = array[index];
	while(current != nullptr)
	{
		if(current -> key == key and current != nullptr)
		{
			return true;
		}
		current = current -> next;
	}
	return false;
}

std::string HashMap::value(const std::string& key) const
{
	if(contains(key) == true)
	{
		int HashValue = hasher(key);
		int index = get_index(HashValue, bucketCount());
		Node* temp = array[index];
		while(temp != nullptr and temp -> key != key)
		{
			if((temp -> key == key) != true)
				temp = temp -> next;
		}
		if(temp -> key == key)
			return temp -> value;
	}
	return "";
}

unsigned int HashMap::size() const
{
	return (unsigned int) sz;
}

unsigned int HashMap::bucketCount() const
{
	return (unsigned int) numBuckets;
}

double HashMap::loadFactor() const
{
	return (double)sz/(double)numBuckets;
}

unsigned int HashMap::maxBucketSize() const
{
	int counter = 0;
	int biggest = 10;

	for(int i = 0; i < bucketCount(); i++)
	{
		Node* temp = array[i];
		while(temp != nullptr)
		{
			counter += 1;
			temp = temp -> next;
		}

		if(biggest <= counter)
			biggest = counter;

	}
	return biggest;
}

void HashMap::clear()
{
	sz = 0;
	for(int i = 0; i < bucketCount(); i++)
	{
		Node* temp = array[i];
		Node* temp1;
		while(!(temp == nullptr))
		{
			delete temp;
			temp1 = array[i] -> next;
			temp = temp1;
		}
	}
	for(int i = 0; i < bucketCount(); i++)
	{
		array[i] = nullptr;
	}
}

