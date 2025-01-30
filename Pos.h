#ifndef POS__H__
#define POS__H__

#ifndef N 
	#define N 8 
#endif 

class Pos {
	public: 
		short int x;
		short int y; 

		Pos(short int x = 0, short int y = 0); 
		void set(const short int &x, const short int &y);
		bool validate() const; 
};

void Pos::set(const short int &x, const short int &y) {
	this->x = x;
	this->y = y; 
	
	return;
}

bool Pos::validate() const {
	return !(x < 0 || x >= N || y < 0 || y >= N);  
}

Pos::Pos(short int x, short int y) {
	this->x = x;
	this->y = y;
}

#endif
