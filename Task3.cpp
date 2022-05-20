#include <bits/stdc++.h>
using namespace std;


template<typename T>
class FlatVector {
private:
	vector<T> flatVec;
	int firstDimSize,
		secondDimSize,
		thirdDimSize;
public:
    /**
	* Constructor of the FlatVector class that creates a 1-D vector out of a 3-D Vector
	* @param matrix - The matrix to be flattened by address
	*/
	FlatVector(vector<vector<vector<T>>>& matrix) {
		firstDimSize = matrix.size();
		secondDimSize = 0;
		thirdDimSize = 0;
		if (matrix.size() > 0)
			secondDimSize = matrix[0].size();
		if (matrix.size() > 0 && matrix[0].size() > 0)
			thirdDimSize = matrix[0][0].size();
		for (size_t i = 0; i < matrix.size(); ++i)
			for (size_t j = 0; j < secondDimSize; ++j)
				for (size_t k = 0; k < thirdDimSize; ++k)
					flatVec.push_back(matrix[i][j][k]);
	}

	/**
	* Access the required element in the 1-D vector using 3-D addressing
	* @param i - The first dimension index of the element in the 3-D representaion
	* @param j - The second dimension index of the element in the 3-D representaion
	* @param k - The third dimension index of the element in the 3-D representaion
	* @return The element in the specified location
	*/
	T get(int i, int j, int k) {
		return flatVec[getCorrespondingIndex(i, j, k,firstDimSize, secondDimSize, thirdDimSize)];
	}

	/**
	* Access the required element in the 1-D vector using 1-D addressing
	* @param y - The index of the element in the 1-D representaion
	* @return The element in the specified location
	*/
	T get(int y) {
		return flatVec[y];
	}

	/**
	* Convert a 3-D matrix addressing into a 1-D matrix addressing
	* @param i - First dimension index in the 3-D matrix
	* @param j - Second dimension index in the 3-D matrix
	* @param k - Third dimension index in the 3-D matrix
	* @param firstDimSize - The size of the 3-D matrix first dimension
	* @param secondDimSize - The size of the 3-D matrix second dimension
	* @param thirdDimSize - The size of the 3-D matrix third dimension
	* @return the 1-D index corresponding to the 3-D representation
	*/
	static int getCorrespondingIndex(int i, int j, int k, int firstDimSize, int secondDimSize, int thirdDimSize) {
		return k + j * secondDimSize + i * secondDimSize * thirdDimSize;
	}

	/**
	* Convert a 1-D matrix addressing into a 3-D matrix addressing
	* @param y - The 1-D index to be converted
	* @param firstDimSize - The size of the 3-D matrix first dimension
	* @param secondDimSize - The size of the 3-D matrix second dimension
	* @param thirdDimSize - The size of the 3-D matrix third dimension
	* @return A vector of 3 elements (i,j,k) representing the 3-D representation of the 1-D index
	*/
	static vector<int> getCorrespondingIndex(int y, int firstDimSize, int secondDimSize, int thirdDimSize) {
		vector<int>realCoordinates(3);
		int totalSize = firstDimSize * secondDimSize * thirdDimSize;
		realCoordinates[0] = y / (secondDimSize * thirdDimSize) ;                //i
		realCoordinates[1] = y % (secondDimSize * thirdDimSize) / secondDimSize; //j
		realCoordinates[2] = y % (secondDimSize * thirdDimSize) % secondDimSize; //k
		return realCoordinates;
	}
};

