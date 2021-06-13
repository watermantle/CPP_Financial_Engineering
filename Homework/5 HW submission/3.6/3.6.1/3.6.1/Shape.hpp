//	Shape header file 
//	Shape class in the ineritance list of the Point and Line
//	Print() function to implement ToString() to each derived class
#ifndef Shape_HPP
#define Shape_HPP

#include <iostream>
using namespace std;

namespace YuBai {
	namespace CAD {
		class Shape {
		private:
			int m_id;									//	member data for id
		public:
			Shape();									//	defualt constructor
			Shape(const Shape& source);					//	copy constructor
			Shape& operator = (const Shape& source);	//	Assignment operator
			virtual ~Shape();							//	destructor
			
			virtual string ToString() const;			//	description
			virtual void Draw() const = 0;				//	pure virtual draw funtion
			void Print() const;							//	Print shape information for all derived class
			int ID() const;								//	retrieve the id of the shape		
		};
	}
}

#endif