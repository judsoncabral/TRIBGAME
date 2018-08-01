#include <iostream>
#include <string>
#include <vector>


class Item{
	private:
		std::string name;
		int id, health, attack, defense;
		float speed;

	public:
		Item (std::string n, int i, int h, int a, int d, float s) : name(n) , id(i), health(h), attack(a), defense(d),speed(s){

		}
		int get_health(){
			return this->health;
		}
		int get_defense(){
			return this->defense;
		}
		float get_speed(){
			return this->speed;
		}
		int get_attack(){
			return this->attack;
		}
		int get_id(){
			return this->id;
		}
		std::string get_name(){
			return this->name;
		}


		void set_health(int h){
			this->health = h;
		}
		void set_defense(int d){
			this->defense = d;
		}
		void set_speed(float s){
			this->speed = s;
		}
		void set_attack(int a){
			this->attack = a;
		}
		void set_name(std::string n){
			this->name = n;
		}
		void set_id(int i){
			this->id = i;
		}
		void remove(){

			this->id = 0;
			this->health = 0;
			this->attack = 0;
			this->name = "0";
			this->speed = 1;
			this->defense = 0;

		}
};

class Bag{

	private:

		std::vector <Item *> bag;
		std::vector < int > BAGqtd;
		int qtd=0;
		int cap= 150;

		int search( int item_id ){
			
			for(int i = 0 ; i < cap ; i++ ){
				if( BAGqtd[i] > 0 ){
					if( bag[i]->get_id() == item_id){
						return i;
					}
				}
			}
	
			return -1;

		}
	public:
		Bag(){
			bag.resize(150);
			BAGqtd.resize(150);
			for(int j = 0 ; j < cap ; j++ ){
				BAGqtd[j] = 0;
			}
		}
		Bag(int i){

			bag.resize(i);
			BAGqtd.resize(i);
			cap = i;

			for(int j = 0 ; j < cap ; j++ ){
				BAGqtd[i] = 0;
			}
		}
		void add_item(Item *item,int amount){

			if( amount > 0){

				if(qtd < cap){

					if ( search( item->get_id() ) != -1 ){

						int x = search( item->get_id() );
						BAGqtd[x] = BAGqtd[x]+amount;

					}else{

						for( int i = 0 ; i < cap ; i++ ){
							if( BAGqtd[i] == 0 ){
								BAGqtd[i] = amount;
								bag[i] = item;
								qtd++;
								return;
							}
						}

					}
					
				}
			}
		}

		void drop_item(int item_id, int amount){

			if( qtd > 0 ){
				if( search( item_id ) != -1 ){
					int x = search( item_id );
					if( BAGqtd[x] - amount < 1){
						BAGqtd[x] = 0;
					}
					else{
						BAGqtd[x] = BAGqtd[x] - amount;
					}
				}
			}
		}

		Item *get_item(int item_id){

			for(int i = 0 ; i < qtd ; i++){
				if( BAGqtd[i] > 0){
					if( bag[i]->get_id() == item_id ){
						return bag[i];
					}
				}
			}
			return nullptr;
		}

		Item *pick_item(int item_id){

			for(int i = 0 ; i < qtd ; i++){
				if( search( item_id ) != -1 ){
					int x = search( item_id );
					BAGqtd[x] = BAGqtd[x]--;
					return bag[i];
				}
			}
			return nullptr;
		}

		int size(){
			return this->qtd;
		}

		bool is_empty(){
			if ( this->qtd == 0 ){
				return true;
			}
			return false;
		}



};

class Player{

	private:
		std::string name;
		int health, speed, attack, defense;
		Bag *bag;

	public:

		Player(int health_p, int defense_p, int attack_p, float speed_p) {
	      this->health = health_p;
	      this->speed = speed_p;
	      this->attack = attack_p;
	      this->defense = defense_p;
	      bag = new Bag(150);
		}
		~Player(){
			delete []bag;
		}
		void Battle(Player &p){

			int p2Health;
			int p1 = this->attack*this->speed;
			int p2 = p.get_defense();

			if( p2-p1 < 0 ){
				p2Health = p.get_health();
				p2Health = p2Health-(this->attack*this->speed - defense);
				p.set_health( p2Health );
			}
		}

		int get_health(){
			return this->health;
		}
		int get_defense(){
			return this->defense;
		}
		int get_speed(){
			return this->speed;
		}
		int get_attack(){
			return this->attack;
		}

		void set_health( int  h ){

		}

		bool is_death(){
			if( this->health <= 0 ){
				return true;
			}
				return false;
		}

};

int main(){
	Player p1(150, 15, 20, 0.5);
	Player p2(100, 20, 20, 0.8);


	// Create items
	Item* item0 = new Item("Item 0", 0, 20, 0, 0,   0);
	Item* item1 = new Item("Item 1", 1, 0, 5, 0,   0);
	Item* item2 = new Item("Item 2", 2, 0, 0, 5,   0);
	Item* item3 = new Item("Item 3", 3, 0, 0, 0, 1.5);
	// Create bag
	std::cout << "2" << std::endl;
	Bag* bag = new Bag(10);

	// Add items to bag
	bag->add_item(item0, 4);
	bag->add_item(item1, 2);
	bag->add_item(item2, 2);
	bag->add_item(item3, 1);

	// Drop an item
	bag->drop_item(3, 1);

	// Get an item
	Item* item = bag->get_item(3);

	if (item == nullptr) {
	std::cout << "There is no Item 3 in the bag." << '\n';
	}
	// Drop an item
	bag->drop_item(0, 1);

	// Get an item
	item = bag->get_item(0);
	std::cout << "Selected item: " << item->get_name() << '\n';

	return 0;

}