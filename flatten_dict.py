import copy

# flatten(dict_object) always returns a new dict
# with keys as str object.
def flatten(a_dict):
	if type(a_dict) != dict: return None
	
	result = {}
	for key in a_dict:
		temp_key = copy.copy(str(key))
		temp_value = copy.deepcopy(a_dict[key])
		
		if type(a_dict[key]) == dict:
			# here temp_value is a dict 
			temp_value = flatten(temp_value)
			
			# produce keys for result
			for t_key in temp_value:
				result[temp_key+"_"+t_key] = temp_value[t_key]
		else:
			result[temp_key] = temp_value
	return result 


d = {
	'A': {
			'a': {'1': 7}, 
			'b': {'3': 8}, 
			'c': 2, 
			'd': 33
	}, 
	'B': {
		'c': {'2': 6, '3': 9, 'another':
				{
					'6': 9, 
					'Z': {'a': 3, 'b': 98}
				}
		}
	},
	'C': {'d': 8, 'g': 9},
	'D': 2
}

fd = flatten(d)
for key in fd:
	print("{}: {}".format(key, fd[key]))
