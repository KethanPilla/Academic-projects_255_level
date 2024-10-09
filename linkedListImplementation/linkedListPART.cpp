#include "linkedList.h"

bool linkedListType::isEmptyList()
{
    return (first == nullptr);
}

linkedListType::linkedListType() //paramater-less constructor
{
    count=0;
    first = nullptr;
    last = nullptr;
}

void linkedListType::destroyList()
{
   nodeType *temp;   //pointer to deallocate the memory
                            //occupied by the node
    while (first != nullptr)   //while there are nodes in
    {                          //the list
        temp = first;        //set temp to the current node
        first = first->link; //advance first to the next node
        delete temp;   //deallocate the memory occupied by temp
    }
    last = nullptr; //initialize last to nullptr; first has
               //already been set to nullptr by the while loop
    count = 0;
}

void linkedListType::initializeList()
{
	destroyList(); //if the list has any nodes, delete them
}

void linkedListType::print()
{
     //iterate over a linked list, we need a temporary pointer
    nodeType* nTptr;
    nTptr = first;
    for(int i = 0; i<count; i++){
        cout<<nTptr->info<<endl;
        nTptr = nTptr->link;
    }
}//end print


int linkedListType::length()
{
    return count;
}  //end length


int linkedListType::front()
{
    if(!isEmptyList()){
        return first->info;
    }
    else{
        cout<<"Error: list is empty."<<endl;
        return -1;
    }
}//end front


int linkedListType::back()
{
    if(!isEmptyList()){
        return last->info;
    }
    else{
        cout<<"Error: list is empty."<<endl;
        return -1;
    }
}//end back


void linkedListType::copyList(const linkedListType& otherList)
{
	nodeType* newNode;
	nodeType* current;
	// case1: is otherList empty
	if(first != nullptr)
	{
		destroyList();
	}
	//case2: am I empty?
	if(otherList.first == nullptr)
	{
		first = nullptr;
		last = nullptr;
		count = 0;
		
	}
	//case2: keep going
	{
		current = otherList.first;
		count = otherList.count;
		
		first = new nodeType;
		first ->info = current ->info;
		first->link = nullptr;
		
		last = first;
		current = current->link;
		
		while(current!= nullptr)
		{
			newNode = new nodeType;
			newNode->info = current->info;
			newNode->link = nullptr;
			
			last->link = newNode;
			last = newNode;
			
			current = current->link;
		}
	}
}//end copyList

linkedListType::~linkedListType() //destructor
{
   destroyList(); //if the list has any nodes, delete them
}//end destructor

linkedListType::linkedListType(const linkedListType& otherList)
{
	first = nullptr;
	copyList(otherList);
}//end copy constructor

//overload the assignment operator
const linkedListType& linkedListType::operator=(const linkedListType& otherList)
{
	if(this!= &otherList)
	{
		copyList(otherList);
	}
    return *this;
}

bool linkedListType::search(const int& searchItem)
{
	nodeType* current;
	bool found = false;
	
	current = first ;
	
	while(current!= nullptr && !found)
	{
		if(current->info == searchItem)
		{
			found = true;
		}
		else
		{
			current = current->link;
		}
	}
	return found;
}

void linkedListType::insert(const int& newItem)
{
     nodeType* temp;
     temp = new nodeType;
     temp->info = newItem;
     temp->link = first;
     first = temp;

     if(last == nullptr){
         last = temp;
     }
     count++;
}

void linkedListType::deleteNode(const int& deleteItem)
{
	nodeType* current;
	nodeType* trailCurrent;
	bool found;
	// case1: is the list empty
	if(first == nullptr)
	{
		cout << "list is empty" << endl;
	}
	//case2: if the first thing is what we are searching
	else if(first->info == deleteItem)
	{
		current = first;
		first = first->link;
		delete current;
		count--;
		if(first == nullptr)
		{
			last = nullptr;
		}
	}
	// case3: otherwise, check the rest of the list
	else
	{
		found = false;
		trailCurrent = first;
		current = first->link;
		
		while(current!= nullptr && !found)
		{
			if(current->info != deleteItem)
			{
				trailCurrent = current;
				current = current->link;
			}
			else
			{
				found = true;
			}
			
		}
		if(found)
		{
			trailCurrent->link = current->link;
			count--;
			if(last == current)
			{
				last = trailCurrent;
			}
			delete current;
		}
		else
		{
			cout <<"not in last";
		}
	}
	
}




