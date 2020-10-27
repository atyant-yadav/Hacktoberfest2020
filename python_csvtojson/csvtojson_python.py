#!/usr/bin/env python
# coding: utf-8

# In[8]:


import csv,json


# In[10]:


def make_json(csvFilePath, jsonFilePath): 
      
    data = {} 
      
    with open(csvFilePath, encoding='utf-8') as csvf: 
        csvReader = csv.DictReader(csvf) 
          
        for rows in csvReader: 
              
            key = rows['No'] 
            data[key] = rows 
  
    with open(jsonFilePath, 'w', encoding='utf-8') as jsonf: 
        jsonf.write(json.dumps(data, indent=4)) 
          
csvFilePath = r'data.csv'
jsonFilePath = r'output.json'
  
make_json(csvFilePath, jsonFilePath)


# In[ ]:




