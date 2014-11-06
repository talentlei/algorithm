#include <iostream>
#include <algorithm>
#include <vector>
/**
 * Knapsack problem
 */

/**
 * [getMostValue 获得最大的价值]
 * @param  Weight [物品重量数组]
 * @param  Value  物品价值数组
 * @param  cap    背包容量
 * @param  size   物品个数
 * @return        最大的价值
 */
int getMostValue(int* Weight , int* Value, int cap,int size){
	int array[cap+1], tmp[cap+1];
	for(int i = 0; i < cap+1; i++){
		array[i] = 0;
		tmp[i] = 0;
	}

	for(int i = 0; i < size; i++){ //item
		for(int j = 1; j < cap+1; j++){ //weight
			if(j >= Weight[i])
				array[j] = ( (tmp[j] > tmp[j-Weight[i]] + Value[i]) ? tmp[j]:(tmp[j-Weight[i]] + Value[i]));
			std::cout << array[j] << "\t";
		}
		for(int k = 0; k < cap+1; k++)
			tmp[k] = array[k];
		std::cout << std::endl;
	}
	return array[cap];
}

int main(){
	int Weight[] = {1,2,3};
	int  Value[] = {60,100,120};
	int mostvalue = getMostValue(Weight, Value, 5, 3);
	std::cout << "max value is " << mostvalue << std::endl;
}