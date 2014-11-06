#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef struct activity{
	int start;
	int end;
	int value;
}Activity;

bool myfunction (Activity a, Activity b) {
	return (a.end < b.end);
}

int getMostProfit(vector<Activity> activities){
	if(activities.size() == 0)
		return 0;

	sort(activities.begin(), activities.end(),myfunction);

	int opt[activities.size()];
	opt[0] = activities[0].value;
	for(int i = 1; i < activities.size(); i++){
		int j;
		for(j = i-1; j >=0; j--){
			if(activities[j].end <= activities[i].start)
				break;
		}
		if(j >=0)
			opt[i] = ((opt[i-1]>opt[j]+activities[i].value)?opt[i-1]:(opt[j]+activities[i].value));
		else opt[i] = ((opt[i-1]>activities[i].value)?opt[i-1]:activities[i].value);
	}
	for(int i = 0; i < activities.size(); i++)\
		cout << opt[i] << endl;
	return opt[activities.size()-1];
}



int main(){
	int starts[] = {1,3,0,5,3,5,6,8,8,2,12};
	int  ends[]  ={4,5,6,7,9,9,10,11,12,14,16};
	int  values[] = {1,2,4,6,4,2,3,3,4,1,3};

	vector<Activity> activities;
	for(int i = 0; i < 11 ; i++){
		Activity tmp;
		tmp.start = starts[i];
		tmp.end  = ends[i];
		tmp.value = values[i];
		activities.push_back(tmp);
	}
	int profit = getMostProfit(activities);
	cout << "mostProfit is "<<profit << endl;
}
