#pragma once
template <
	typename _Ty,
	int _SIZE1,
	int _SIZE2,
	int _SIZE3
>
class DATA_UNIT
{
	using type = _Ty;
	using pointer = _Ty*;
	using reference = _Ty&;
public:
	DATA_UNIT(type*,type*);
	DATA_UNIT();
	~DATA_UNIT();

private:
	pointer REST_INFO = nullptr;
	pointer REST_MENU = nullptr;
	type _ID;
};

template<typename _Ty, int _SIZE1, int _SIZE2, int _SIZE3>
inline DATA_UNIT<_Ty, _SIZE1, _SIZE2, _SIZE3>::DATA_UNIT(type* REST_INFO, type* REST_MENU)
{
	this->REST_INFO = REST_INFO;
	this->REST_MENU = REST_MENU;
}

template <typename _Ty, int _SIZE1, int _SIZE2, int _SIZE3>
inline DATA_UNIT<_Ty, _SIZE1, _SIZE2, _SIZE3>::DATA_UNIT()
{

}

template <typename _Ty, int _SIZE1, int _SIZE2, int _SIZE3>
inline DATA_UNIT<_Ty, _SIZE1, _SIZE2, _SIZE3>::~DATA_UNIT()
{

}