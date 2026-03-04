#include <iostream>
#include <string>
#include <limits>

using namespace std;

int setStatus(string name, int min)										// 능력치 입력 함수
{
	int num;

	while (true)
	{
		cout << name << "의 값을 입력해주세요(최소값: " << min << "): ";
		if (!(cin >> num) || num <= min)
		{
			cout << "올바른 값이 아닙니다." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			return num;
		}
	}
}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)				// 포션 개수 초기화 함수
{
	*p_HPPotion = count;
	*p_MPPotion = count;
}

void chargePotion(int count, int* p_HPPotion, int* p_MPPotion)			// 포션 충전 함수
{
	*p_HPPotion += count;
	*p_MPPotion += count;
}

int main()
{
	int status[4] = { 0, };
	int HPPotion = 0;
	int MPPotion = 0;
	int* ptr_HP = &HPPotion;
	int* ptr_MP = &MPPotion;
	setPotion(5, ptr_HP, ptr_MP);
	int level = 1;
	int menu;

	status[0] = setStatus("HP", 50);
	status[1] = setStatus("MP", 50);
	status[2] = setStatus("공격력", 0);
	status[3] = setStatus("방어력", 0);

	while (true)
	{
		cout << "1.HP UP / 2.MP UP / 3.공격력 UP / 4.방어력 UP / 5.현재 능력치 / 6.Level Up / 0.나가기" << endl;
		if (!(cin >> menu))
		{
			menu = 7;			// 입력 시 문자가 들어가면 menu에 0값이 들어가 나가기 되어버림. 임의로 숫자 7 대입.
		}
		switch (menu)
		{
		case 0:
			return 0;
		case 1:
			if (HPPotion > 0)
			{
				status[0] += 20;
				--HPPotion;
				cout << "HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
				cout << "현재 HP: " << status[0] << endl;
				cout << "남은 HP포션 수: " << HPPotion << endl;
			}
			else
			{
				cout << "남은 HP포션이 없습니다." << endl;
			}
			break;
		case 2:
			if (MPPotion > 0)
			{
				status[1] += 20;
				--MPPotion;
				cout << "MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
				cout << "현재 MP: " << status[1] << endl;
				cout << "남은 MP포션 수: " << MPPotion << endl;
			}
			else
			{
				cout << "남은 MP포션이 없습니다." << endl;
			}
			break;
		case 3:
			status[2] *= 2;
			cout << "공격력이 2배로 증가했습니다." << endl;
			cout << "현재 공격력: " << status[2] << endl;
			break;
		case 4:
			status[3] *= 2;
			cout << "방어력이 2배로 증가했습니다." << endl;
			cout << "현재 방어력: " << status[3] << endl;
			break;
		case 5:
			cout << "현재 레벨: " << level << endl;
			cout << "현재 HP: " << status[0] << endl;
			cout << "현재 MP: " << status[1] << endl;
			cout << "현재 공격력: " << status[2] << endl;
			cout << "현재 방어력: " << status[3] << endl;
			cout << "남은 포션의 개수: " << HPPotion << " / " << MPPotion << endl;
			break;
		case 6:
			chargePotion(1, ptr_HP, ptr_MP);
			++level;
			cout << "레벨업! HP/MP포션이 지급됩니다." << endl;
			cout << "현재 레벨: " << level << endl;
			cout << "현재 포션 수: " << HPPotion << " / " << MPPotion << endl;
			break;
		default:
			cout << "올바른 값이 아닙니다." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
}