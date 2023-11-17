#pragma once

template <typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;

	Node(T data, Node<T>* next, Node<T>* prev)
		: data(data), next(next), prev(prev) {
	}
};

template <typename T>
class MyList
{
	Node<T>* begin;
	Node<T>* end;
public:
	MyList() : begin(nullptr), end(nullptr) {
	}

	MyList(const MyList<T>& existMyList) {
		Node<T>* iter = existMyList.begin;
		Node<T>* temp = new Node<T>();
		temp->data = iter->data;
		// ...
	}

	~MyList() {
		clear();
	}

	void clear() {
		if (begin != nullptr) {
			Node<T>* iter = begin;
			//
			while (iter->next != nullptr) {
				iter = iter->next;
				delete iter->prev;
			}
			//
			delete iter;
			begin = nullptr;
			end = nullptr;
		}
		
	}

	void pushBack(const T& data) {
		Node<T>* temp = new Node<T>(data, nullptr, nullptr);
		//
		if (begin == nullptr) { // якщо список порожній
			begin = end =  temp;
		}
		//
		else {					// якщо список heпорожній
			end->next = temp;
			temp->prev = end; 
			end = temp;
		}
	}

	void pushFirst(const T& data) {
		Node<T>* temp = new Node<T>(data, nullptr, nullptr);
		if (begin == nullptr) {
			begin = end = temp;
		}
		else {
			begin->prev = temp->next;
			temp->next = begin;
			begin = temp;
			
		}
		
	}

	//void pushIter(const T& data, int pos) {
	//	Node<T>* temp = new Node<T>(data, nullptr, nullptr);
	//	if (begin == nullptr) {
	//		begin = end = temp;
	//	}
	//	else {
	//		Node<T>* iter = begin;
	//		int counter = 0;
	//		while (iter->next != nullptr) {
	//			iter = iter->next;
	//			counter++;
	//		}
	//		
	//		if (pos <= counter) {
	//			int k = 0;
	//			iter = begin;
	//			for (int i = 1; i < pos; ++i) {
	//				iter = iter->next;
	//			}
	//			temp->next = iter->next;
	//			temp->prev = iter;
	//			iter->next->prev = temp;
	//
	//		}
	//		else {
	//			
	//			std::cout << " Added at the end as position is bigger than list\n";
	//		}
	//		delete iter;
	//		
	//	}
	//	

	//}

	void display() const {
		if (begin != nullptr) {
			std::cout << "\n List is \n" << std::endl;
			Node<T>* iter = begin;
			while (iter->next != nullptr) {
				std::cout << "  " << iter->data;
				iter = iter->next;
			}
			std::cout << "  " << iter->data;
			std::cout << std::endl;
		}
		else {
			std::cout << "\n List is empty!\n" << std::endl;
		}

	}
	};


