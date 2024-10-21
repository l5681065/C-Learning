
#include <iostream>
using namespace std;

class People;
class Friend;

class People
{
        public: People(float money) :myMoney(money)
       {

       }

    friend float TotalMoney(People  people, People anotherPeople);

    friend class Friend;
private:
       float myMoney = 0.0f;
};

class Friend
{
public:
    Friend(People people) :people(people)
    {

    }
    void SeePeopleMoney()
    {
        cout << people.myMoney <<endl;
    }
private:
    People people;
};



//
//friend float TotalMoney(People people, People anotherPeople) 严重性	代码	说明	项目	文件	行	禁止显示状态	详细信息
//错误	C2255	“friend” : 不允许位于类定义之外	Friend	G : \GitHubProject\C - Learning\LearningC\Friend\Friend.cpp	15
float TotalMoney(People people, People anotherPeople)
{
    return people.myMoney + anotherPeople.myMoney;
}

int main()
{
    People people = People(5.0f);
    People anotherPeople = People(5.0f);

    cout << TotalMoney(people,anotherPeople) <<endl;

    Friend aFriend = Friend(people);
    aFriend.SeePeopleMoney();
}
