#include <iostream>
#include<string>
using namespace std;
class DataBase {
public:
    DataBase(const DataBase&) = delete;
    void operator=(const DataBase&) = delete;
    static DataBase* get_connect() {
        if (DataBaseConnect == nullptr)
            DataBaseConnect = new DataBase;
        return DataBaseConnect;
    }

    string get_data()const {
        return data;
    }
    void set_data(string str) {
        data += str;      
    }
private:
    DataBase() {
        cout << "конструктор"<<endl;
    }
    static DataBase* DataBaseConnect;
    string data;
};
DataBase* DataBase::DataBaseConnect = nullptr;
int main()
{
    setlocale(LC_ALL, "ru");
    DataBase::get_connect()->set_data("новые данные1");
    DataBase::get_connect()->set_data("новые данные2\n");
    DataBase::get_connect()->set_data("новые данные3\n");

    cout << "все данные:\n" << DataBase::get_connect()->get_data()<<endl;
    
    return 0;
}

