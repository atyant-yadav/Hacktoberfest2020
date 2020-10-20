# install xmltodict in comand prompt
# pip install xmltodict and check it using pip freeze
import xmltodict

handle=open("xml_input.xml","r")

content = handle.read()
# print(content)

# we need to convert the xml file to dict file for updating

d = xmltodict.parse(content)
# print(d)
# it is of type OrderDict. It is one of the class we have in collections
# print(d['Result']['Message'])

d['Result']['RequestCode']=4
# print(d)

# if we want to convert the python file to xml we need to use unparse function

x = xmltodict.unparse(d)
print(x)

# We can similary write it in any file by using it in write mode