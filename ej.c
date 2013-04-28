#include <stdlib.h>
#include <string.h>
#include <jansson.h>

/*I used Jansson because Jansson have a free software license (MIT LICENSE) and this project has a very good documentation*/

void type_of(json_t *root){
	json_type type = json_typeof(root);
	switch (type) {
		case JSON_NULL: printf("json_type_null\n");
			break;
		case JSON_REAL: printf("json_type_double\n");
			break;
		case JSON_INTEGER: printf("json_type_int\n");
			break;
		case JSON_OBJECT: printf("json_type_object\n");
			break;
		case JSON_ARRAY: printf("json_type_array\n");
			break;
		case JSON_STRING: printf("json_type_string\n");
			break;
	}
}
json_t* load_file(char *url){
	json_t *json;
    json_error_t error;
    json = json_load_file(url, 0, &error);
    if(!json) {
        printf("Error in the line: %d: %s \n",error.line, error.text);
    }
    return json;
}

int main(void) {
	json_t *root;
	const char *key;
	json_t *value;
	json_t *value2;
	root = load_file("ejemplo2.json");
	printf("Type of the root: ");
	type_of(root);
	void *iter = json_object_iter(root);
	json_object_foreach(root, key, value) {
		printf("Root's key\n");
		printf("	-%s\n",key);
		printf("Type of Value: ");
		type_of(value);
		json_t* temp;
		printf("Values:\n");
		for(int i = 0; i<(int)json_array_size(value); i++){
			temp = json_array_get(value,(size_t)i);
			json_object_foreach(temp, key, value2) {
				printf("	%s : %s\n",key,json_string_value(value2));
			}
		}
	}
}
