#ifndef DATA_H
# define DATA_H

# include <iostream>

class Data
{
	private:
		int _value;
	public:
		Data();
		Data(int value);
		Data(const Data &other);
		~Data();

		Data &operator=(const Data &other);

		int getDataValue(void) const;
};

#endif
