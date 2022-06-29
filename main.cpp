#include<iostream>
#include <cstring>
using namespace std;

class MyString
{
public:
    MyString(const char* str)
    {
        length =  strlen(str);
        this->str = new char[length + 1];
        for(int i = 0; i < length; i++)
        {
            this->str[i] = str[i];
        }
        this->str[length] = '\0';
    }
    MyString()
    {
        str = nullptr;
        length = 0;
    }
    ~MyString()
    {
        delete [] this->str;
    }
    void Print()
    {
        cout << str << endl;
    }
    MyString(const MyString& other)
    {
        this->length = strlen(other.str);
        this->str = new char[length+1];
        for(int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];
        }
        this->str[length] = '\0';
    }
    MyString& operator=(const MyString& other)
    {
        if(this->str!=nullptr)
        {
            delete [] str;
        }
        length = strlen(other.str);
        this->str = new char[length+1];
        for(int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];
        }
        this->str[length] = '\0';
        return *this;
    }
    MyString operator+(MyString& other)
    {
        MyString tmp;
        int thisLength = strlen(this->str);
        int otherLength = strlen(other.str);
        tmp.length = thisLength + otherLength;
        tmp.str = new char[thisLength + otherLength + 1];
        int i = 0;
        for(; i < thisLength; i++)
        {
            tmp.str[i] = this->str[i];
        }
        for(int j = 0; j < otherLength; i++, j++)
        {
            tmp.str[i] = other.str[j];
        }
        tmp.str[tmp.length] = '\0';
        return tmp;
    }
    int Length()
    {
        return length;
    }
    bool operator==(MyString& other)
    {
        if(this->length != other.length)
        {
            return false;
        }
        for(int i = 0; i < this->length; i++)
        {
            if(this->str[i]!=other.str[i])
            {
                return false;
            }
        }
        return true;
    }
    bool operator!=(MyString& other)
    {
        return !(this->operator==(other));
    }
    char& operator[](int index)
    {
        return this->str[index];
    }
    MyString(MyString&& other)
    {
        this->length = other.length;
        this->str = other.str;
        other.str = nullptr;
    }
private: 
    char* str;
    int length;
};

int main()
{
    MyString str = "Test";
    str.Print();
    MyString str1;
    str1 = "test";
    str1.Print();
    MyString str2;
    str2 = str + str1;
    str2.Print();
    cout << str.Length() << endl;
    cout << str1.Length() << endl;
    cout << str2.Length() << endl;
    bool equal = str == str1;
    bool equal1 = str!= str1;
    cout << equal << endl;
    cout << equal1 << endl;
    cout << str[1] << endl;
    str[1] = 'd';
    str.Print();
    


    return 0;
}