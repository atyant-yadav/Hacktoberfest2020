import numpy as np 
import pandas as pd
import matplotlib.pyplot as plt

dataset=pd.read_csv("Salary_Data.csv")

X=dataset.iloc[:,:-1].values
Y=dataset.iloc[:,-1].values


from sklearn.model_selection import train_test_split

X_train,X_test,Y_train,Y_test=train_test_split(X,Y,test_size=0.3,random_state=0)

from sklearn.linear_model import LinearRegression

lr=LinearRegression()

lr.fit(X_train,Y_train)

y_pred=lr.predict(X_test)

plt.scatter(X_train,Y_train)
plt.plot(X_train,lr.predict(X_train))
plt.title("TRAINING")
plt.show()

plt.scatter(X_test,Y_test)
plt.plot(X_test,y_pred)
plt.title("TESTING")
plt.show()