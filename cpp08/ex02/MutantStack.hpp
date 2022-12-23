#pragma once

template <typename T>
class MutantStack: public std::stack<T>{
	public:
	    typedef typename std::vector<T>::iterator iterator;
		MutantStack(){}
		MutantStack(const MutantStack& src): _stack(src._stack){}
		~MutantStack(){}
		MutantStack &operator=(const MutantStack& src){
			this->_stack = src._stack;
			return *this;
		}
		void push(T src){
			this->_stack.push_back(src);
		}
		void pop(){
			this->_stack.pop_back();
		}
		size_t size(){
			return _stack.size();
		}
		T top(){
			return this->_stack.back();
		}
		iterator begin(){
			return this->_stack.begin();
		}
		iterator end(){
			return this->_stack.end();
		}
	private:
		std::vector<T> 	_stack;
};
