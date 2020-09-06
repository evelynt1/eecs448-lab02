/**
*	@author 
*	@date 
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	int length;
	while(head != NULL)
	{
		length++;
		head = head->next;
	}
	return(length);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;
	temp = head;
	current = head;

	while (current != NULL && current->number != value)
        {
       	 	temp = current;
        	current = current->next;
        }
    	if (current != NULL)
    	{	
        	searchedValue = current;
        	current = current->next;
        	std::cout << "-" << searchedValue  << "Found";
    	}
    	else
    	{
        	std::cout << "Not found.";
    	}
	
	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	if(m_length == 0)
	{
		return(false);
	}
	else if(m_length == 1)
	{
		removeFront();
		return(true);
	}
	else
	{
		Node<T>* lastNode  = m_front;
		Node<T>* secondintoLast = m_front;
		for(int i = 1; i <= (m_length-1); i++)
		{
			temp = temp -> getNext();
		}
		for(int i = 1; i < m_length-1; i++)
		{
			temp2 = temp2->getNext();
		}
		delete temp;
		temp2 -> setNext(nullptr);
		m_length = m_length - 1;
		return(true);
	}

	return(isRemoved);
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
