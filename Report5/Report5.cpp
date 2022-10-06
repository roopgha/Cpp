#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>

using namespace std;

class Bus {
public:
	//min
	int bussesf_run = 20;

	//hour
	int first_bus = 6;
	int last_bus = 22;

	//meter
	int distance = 470;
};

class User {
public:
	//Per Hour
	int userWalk_speed = 4;
};

class Time {
public:
	int hour;
	int min;

	void GetTime() {
		rawTime = time(NULL);
		pTimeInfo = localtime(&rawTime);

		hour = pTimeInfo->tm_hour;
		min = pTimeInfo->tm_min;
	
		cout << hour << min << endl;
	}

private:
	time_t rawTime;
	struct tm* pTimeInfo;
};

class TimeCal {
public: 
	void PrintTimeToGoOut(int hour, int min) {
		hour_ = hour;
		min_ = min;
		if (hour_ < bus.first_bus || hour_ > bus.last_bus) {
			cout << "6시 13분에 출발하세요" << endl;
		}
		else {
			cout << hour_ << "시 " << TimeToGoOut(min) << "분에 출발하세요";
		}
	}

private:
	User user;
	Bus bus;
	Time time;

	int hour_;
	int min_;
	int changePerMin = (user.userWalk_speed * 1000) / 60;
	int TimeToGoBusStop = bus.distance / changePerMin;

	int TimeToGoOut(int min) {

		if (min >= 53) {
			hour_++;
			return 20 - TimeToGoBusStop;
		}
		else if (min >= 33) {
			return 60 - TimeToGoBusStop;
		}
		else if (min >= 13 && min < 33) {
			return 40 - TimeToGoBusStop;
		}
		else if (min < 13) {
			return 20 - TimeToGoBusStop;
		}
		else {
			return min - TimeToGoBusStop;
		}

	}
};

int main() {
	Time time;
	TimeCal timeCal;

	time.GetTime();
	cout << time.hour << time.min << endl;
	timeCal.PrintTimeToGoOut(time.hour, time.min);
	return 0;
}