string = """line1
line2
line3
line4
line5"""
str_list = string.split('\n')
str_list[3] = "my new line value"
string = "\n".join(str_list)
print(string)
