
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "parson.h"
typedef struct Item
{
	char name[50];
	int price;
}Item;

int main()
{
	printf("JSON 파일 활용하기 예제\n\n");

	//printf("이름 : %s | 가격 : %d\n", item1.name, item1.price);

	JSON_Value* root_value;
	JSON_Array* items;
	JSON_Object* root_Object;

	root_value = json_parse_file("itemDB.json");	
	root_Object = json_value_get_object(root_value);
	
	items = json_object_get_array(root_Object, "items");  

	// object에서 배열을 가져오겠다  

	// 배열에서 n번째 원소(object)를 가져와서 출력하겠다.
	
	Item itemStruct[4];

	for (int i = 0; i < json_array_get_count(items); i++)
	{
		JSON_Object* array_object;
		array_object = json_array_get_object(items, i);

		strcpy(itemStruct[i].name, json_object_dotget_string(array_object, "name"));
		itemStruct[i].price = json_object_dotget_number(array_object, "price");
		//printf("이름 : %s | 가격 : %.0f\n",
		//	json_object_dotget_string(array_object, "name"),
		//	json_object_dotget_number(array_object, "price")
		//);
	}

	for (int i = 0; i < 4; i++)
	{
		printf("이름 : %s | 가격 : %d\n", itemStruct[i].name, itemStruct[i].price);
	}

	
	
	

	
	














	//root_Object = json_value_get_object(root_value);
	//commits = json_object_get_array(root_Object, "items");
	//
	//JSON_Object* temp = json_array_get_object(commits,0);
	//
	//
	//printf("이름 : %s | 가격 : %.0f\n",
	//	json_object_dotget_string(temp, "name"),
	//    json_object_dotget_number(temp, "price")
	//);		


}