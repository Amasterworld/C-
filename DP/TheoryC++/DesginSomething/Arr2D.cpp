// design the data structure that are stored consecutively in memory - 
// the dimension of this Arr2D should be set via constructor with arbitraty data
// implement the method for read and/write the cells of matrix as well as the  overloading operator [][] like vector
// function to construct a new matrix class with all elements set to one 
// the lines are marked with a comment: cannot be changed that means 
// the students should follow these designs


#include <iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

//  arbitraty data -->template
template<class T> class Arr2D {

private:
	unsigned m_rows{}, m_cols{};
	vector<T>m_data; // consecutive memory
public:
	//constructor
	Arr2D(unsigned rows, unsigned cols) : m_rows(rows), m_cols(cols) {
		m_data.resize(m_rows * m_cols);
		
	}

	~Arr2D(){} // not important for this problem

	//function

	// in main() --> Arr2D<int>::One(4, 5)
	// One(4,5) should be a function that can be access directly from class Arr2D<int> 
	//--> only static function can do it (FROM MY KNOWLEGE)
	// auto arr = Arr2D<int>::One(4, 5);  //and then
	// arr.getEle(1,1) = 1;  
	//--> that means arr should be an object --> One MUST return the object --> data type for One should be Matrix<int>
	// to fill all cells of the array 2D to be 1, we should access to the vector data, 
	// and One is a static function, so CANNOT access to the data directly from the class, need to create an object to access

	static Arr2D<int> One(unsigned x, unsigned y){
		Arr2D<int> arr(x, y);
		fill(arr.m_data.begin(), arr.m_data.end(), 1);
		return arr;

	}
	
	int getCols() const { // int here because  Arr2D <int>& arr 
		return m_cols;
	}
	
	//int getEle(unsigned x, unsigned y) const {
	//	return m_data[x * m_cols + y];
	//}
	// but int main() -->  arr.getEle(1, 1) = 1;                     
	//arr.getEle(1,1) can be assigned that means its should be returned by reference,

//	int& getEle(unsigned x, unsigned y) const {
//		return m_data[x * m_cols + y];
//	}
	// but arr passed by ref, is a const object. that means we need to put const int&  getEle(unsigned x, unsigned y) const;
	// finally:
	
	const int& getEle(unsigned x, unsigned y) const {
				return m_data[x * m_cols + y];
	}
	// so far arr.getEle(1,1 ) still has an error, it cannot be assigned when all are const
	// OVERLOADING FUNCTION - rare to use

	int& getEle(unsigned x, unsigned y) {
		return m_data[x * m_cols + y];
	}
};
 

	
		

int getTopRight(const Arr2D <int>& arr) {       // cannot be changed
	auto top_right_coord = arr.getCols() - 1;	// cannot be changed
	return arr.getEle(0, top_right_coord);	// cannot be changed
	
}

int main()
{
	auto arr = Arr2D<int>::One(4, 5); // cannot be changed
	arr.getEle(1, 1) = 1;                     // cannot be changed
	//arr.getEle(1,1) can be assigned that means its should be returned by reference, 
	
	return getTopRight(arr);                  // cannot be changed
}


