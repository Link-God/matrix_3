#include "matrix.hpp"

template < typename T > 
matrix_t<T>::matrix_t() : elements_{ nullptr }, rows_{ 0 }, collumns_{ 0 }
{
}

template < typename T > 
matrix_t<T>::matrix_t( matrix_t<T> const & other )
{
	this->rows_ = other.rows_;
	this->collumns_ = other.collumns_;
	this->elements_ = new float *[this->rows_];
	for (std::size_t i = 0; i < this->rows_; i++) {
		elements_[i] = new float[this->collumns_];
		for (std::size_t j = 0; j < this->collumns_; j++) {
			this->elements_[i][j] = other.elements_[i][j];
		}
	}
}

template < typename T > 
matrix_t<T> & matrix_t<T>::operator =( matrix_t<T> const & other )
{
	for (unsigned int i = 0; i <this->rows_; i++) {
		delete[] this->elements_[i];
	}
	delete[] this->elements_;
	this->rows_ = other.rows_;
	this->collumns_ = other.collumns_;
	this->elements_ = new float * [rows_];
	for (unsigned int i = 0; i < this->rows_; i++) {
		this->elements_[i] = new float[this->collumns_];
		for (unsigned int j = 0; j < this->collumns_; j++) {
			this->elements_[i][j] = other.elements_[i][j];
		}
	}
	return *this;
}

template < typename T > 
matrix_t<T>::~matrix_t()
{
	for (unsigned int i = 0; i < this->rows_; i++) {
		delete[] this->elements_[i];
	}
	delete[] this->elements_;	
}

template < typename T > 
std::size_t matrix_t<T>::rows() const
{
    return rows_;
}

template < typename T > 
std::size_t matrix_t<T>::collumns() const
{
    return collumns_;
}

template < typename T > 
matrix_t<T> matrix_t<T>::operator +( matrix_t<T> const & other ) const
{
	matrix_t<T> result;
	if (this->rows_ == other.rows_ && this->collumns_ == other.collumns_) {
	  	result.elements_ = new float *[this->rows_];
		for (std::size_t i = 0; i<this->rows_; i++) {
			result.elements_[i] = new float [this->collumns_];
		}
		result.rows_ = this->rows_;
		result.collumns_ = this->collumns_;
		
		for (std::size_t i = 0; i<result.rows_; i++) {
			for (std::size_t j = 0; j<result.collumns_; j++) {
				result.elements_[i][j] = elements_[i][j] + other.elements_[i][j];
			}
		}
	}
	else {
		throw 3;
	}
	return result;
}

template < typename T > 
matrix_t<T> matrix_t<T>::operator -( matrix_t<T> const & other ) const
{
	matrix_t<T> result;
	if (this->rows_ == other.rows_ && this->collumns_ == other.collumns_) {
		result.elements_ = new float *[this->rows_];
		for (std::size_t i = 0; i < this->rows_; i++) {
			result.elements_[i] = new float[this->collumns_];
		}
		result.rows_ = this->rows_;
		result.collumns_ = this->collumns_;
		for (std::size_t  i = 0; i < this->rows_; i++) {
			for (std::size_t j = 0; j < this->collumns_; j++) {
				result.elements_[i][j] = this->elements_[i][j] - other.elements_[i][j];
			}
		}
	}
	else {
		throw 3;
	}
	return result;
}

template < typename T > 
matrix_t<T> matrix_t<T>::operator *( matrix_t<T> const & other ) const
{
	matrix_t<T> result;
	if (this->collumns_ == other.rows_) {
		result.rows_ = this->rows_;
		result.collumns_ = other.collumns_;
		result.elements_ = new float *[this->rows_];
		for (std::size_t i = 0; i < this->rows_; ++i) {
			result.elements_[i] = new float[other.collumns_];
		}
		for (std::size_t i = 0; i < this->rows_; i++) {
			for (std::size_t j = 0; j < other.collumns_; j++) {
				int res = 0;
				for (std::size_t k = 0; k < this->collumns_; k++) {
					res += this->elements_[i][k] * other.elements_[k][j];
				}
				result.elements_[i][j] = res;
			}
		}
	}
	else {
		throw 3;
	}
	return result;
}

template < typename T > 
matrix_t<T> & matrix_t<T>::operator -=( matrix_t<T> const & other )
{
	if (this->rows_ == other.rows_ && this->collumns_ == other.collumns_) {
		for (std::size_t  i = 0; i < this->rows_; i++) {
			for (std::size_t j = 0; j < this->collumns_; j++) {
				this->elements_[i][j] -= other.elements_[i][j];
			}
		}
	}
	else {
		throw 3;
	}
	return *this;
}

template < typename T > 
matrix_t<T> & matrix_t<T>::operator +=( matrix_t<T> const & other )
{
	
	if (this->rows_ == other.rows_ && this->collumns_ == other.collumns_) {
		for (std::size_t  i = 0; i < this->rows_; i++) {
			for (std::size_t j = 0; j < this->collumns_; j++) {
				this->elements_[i][j] += other.elements_[i][j];
			}
		}
	}
	else {
		throw 3;
	}
	return *this;
}

template < typename T > 
matrix_t<T> & matrix_t<T>::operator *=( matrix_t<T> const & other )
{
	if (this->collumns_ == other.rows_) {
		matrix_t result;
		result.rows_ = this->rows_;
		result.collumns_ = other.collumns_;
		result.elements_ = new float *[this->rows_];
		for (std::size_t i = 0; i < this->rows_; ++i) {
			result.elements_[i] = new float[other.collumns_];
		}
		for (std::size_t i = 0; i < this->rows_; i++) {
			for (std::size_t j = 0; j < other.collumns_; j++) {
				int res = 0;
				for (std::size_t k = 0; k < this->collumns_; k++) {
					res += this->elements_[i][k] * other.elements_[k][j];
				}
				result.elements_[i][j] = res;
			}
		}
		*this = result;
	}
	else {
		throw 3;
	}
	return *this;
}

template < typename T > 
bool verification (matrix_t<T> const & mat1 ,char  op  , matrix_t<T> const & mat2)
{
	matrix_t<T> result ;
	bool success = true ;
	switch(op){
			case'+':{
				try{
					result= mat1 + mat2 ;
					
				}
				catch(int){
					success = false;
				}
				break;
			}
			case'-':{
				try{
					result= mat1 - mat2 ;
					
				}
				catch(int){
					success = false;
				}
				break;
			}
			case'*':{
				try{
					result= mat1 * mat2 ;
					
				}
				catch(int){
					success = false;
				}
				break;
			}
	}
	return success;
}

template < typename T > 
std::istream & matrix_t<T>::read( std::istream & stream )
{
    std::size_t rows;
    std::size_t collumns;
    char symbol;
    
    bool success = true;
    if( stream >> rows && stream >> symbol && symbol == ',' && stream >> collumns ) {
        float ** elements = new float *[ rows ];
        for( std::size_t i = 0; success && i < rows; ++i ) {
            elements[ i ] = new float[ collumns ];
            for( std::size_t j = 0; j < collumns; ++j ) {
                if( !( stream >> elements[ i ][ j ] ) ) {
                    success = false;
                    break;
                }
            }
        }
        
        if( success ) {
            for( std::size_t i = 0; i < rows_; ++i ) {
                delete [] elements_[ i ];
            }
            delete [] elements_;
            
            rows_ = rows;
            collumns_ = collumns;
            elements_ = elements;
        }
        else {
            for( std::size_t i = 0; i < rows; ++i ) {
                delete [] elements[ i ];
            }
            delete [] elements;
        }
    }
    else {
        success = false;
    }
    
    if( !success ) {
        stream.setstate( std::ios_base::failbit );
    }
    
	return stream;
}

template < typename T > 
std::ostream & matrix_t<T>::write( std::ostream & stream ) const
{
    stream << rows_ << ", " << collumns_;
    for( std::size_t i = 0; i < rows_; ++i ) {
        stream << '\n';
        for( std::size_t j = 0; j < collumns_; ++j ) {
            stream << elements_[ i ][ j ];
            if( j != rows_ - 1 ) {
                stream << ' ';
            }
        }
    }
    
	return stream;
}
