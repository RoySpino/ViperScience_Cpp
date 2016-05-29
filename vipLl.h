#ifndef VIPLL_H
#define VIPLL_H
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class vipLl{
	private:
		int count;
		struct list{
			T data;
			int id;
			list *next, *before;
		};
		list *Root,
		     *start,
		     *end;
		//////////////////////////////////////////////
		list *newNode(const T &d){
			T D=d;
			list *tm=NULL;

			tm = new list;
			tm->next = NULL;
			tm->before = NULL;
			tm->data = D;
			return tm;
		}
		void reAssignID(){
			list *trav = Root;
			for(int i=0; i<count; i++){
				trav->id = i;
				trav = trav->next;
			}
		}
	public:
		vipLl(){
			Root = start = end = NULL;
			count =0;
		}
		int size(){
			return count;
		}
		void erase(){
			list *trav =Root,
			     *killNode;
			// if already empty do nothing
			if(trav == NULL)
				return;

			while(trav->next != NULL){
				killNode = trav;
				trav = trav->next;
				delete killNode;
			}
			delete trav;
			Root = NULL;
			count = 0;
		}
		void erase(int i){
			list *trav =Root,
			     *killNode = trav;;
			// if already empty do nothing
			if(trav == NULL)
				return;

			--count;
			// find the offending node
			while(trav->id != i)
				trav = trav->next;

			// set killNode to travel
			killNode = trav;

			// reassign key nodes
			if(killNode != Root){
				(killNode->next)->before = (killNode->before);
				(killNode->before)->next = (killNode->next);
				reAssignID();
			}if(killNode == Root){
				Root = killNode->next;
				Root->before = NULL;
				start = Root;
				reAssignID();
			}if(killNode == end){
				end = killNode->before;
				end->next = NULL;
			}

			// remove the node
			delete killNode;

			return;
		}
		void erase(int s, int e){
			list *trav =Root,
			     *fndNode,
			     *killNode = trav;;
			// if already empty do nothing
			if(trav == NULL)
				return;
			count = ((e+s)>count)?count -(count-s):count - e;
			// find the offending node
			while(trav->id != s)
				trav = trav->next;
			fndNode = trav;
			// set killNode to travel
			for(int i=0; i<e and trav !=NULL; i++){
				killNode = trav;
				trav = trav->next;

				if(killNode->before != NULL and killNode->next !=NULL){
					(killNode->next)->before = killNode->before;
					(killNode->before)->next = killNode->next;
				}
				if(killNode == Root){
					start =trav;
					Root =trav;
					Root->before = NULL;
				}
				if(killNode == end){
					end = fndNode;
					end->next =NULL;
				}
				delete killNode;
			}
			// reassign ID
			reAssignID();
		}

		void add(const T &d){
			T D=d;
			list *trav = Root;
			if(trav == NULL or count==0){
				Root = newNode(D);
				Root->id =count;
				start = end = Root;
			}else{
				end->next = newNode(D);
				(end->next)->before = end;
				(end->next)->id = count;
				end = end->next;
			}
			count++;
		}
		void push(const T &d){
			T D=d;
			add(D);
		}
		T pop(){
			T output;
			list *killNode;
			killNode = end;
			output = end->data;

			end = end->before;
			Root = start = (end == NULL)?NULL:Root;
			delete killNode;

			count--;
			return output;
		}
		void enque(const T &d){
			T D=d;
			add(D);
		}
		T deque(){
			T output;
			list *killNode;
			output = start->data;
			killNode = start;

			start = start->next;
			Root = start;
			delete killNode;

			count--;
			reAssignID();
			return output;
		}
		T &operator[](int index){
			list *temp = Root;

			while(index < count and temp->next !=NULL){
				if(temp->id == index)
					return temp->data;
				temp = temp->next;
			}
			return temp->data;

		}
		~vipLl(){
			list *trav =Root,
			     *killNode;
			if(trav != NULL and count !=0){
				while(trav->next != NULL){
					killNode = trav;
					trav = trav->next;
					delete killNode;
				}
				delete trav;
				Root = NULL;
			}
		}
};
#endif
