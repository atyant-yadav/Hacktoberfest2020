import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#reading data from the csv file
dataset=pd.read_csv("Data.csv")

#Seperating dataset into dependent and independent variables
X=dataset.iloc[:,:-1].values
Y=dataset.iloc[:,-1].values

#removing NULL values from the dataset

from sklearn.impute import SimpleImputer

imputer=SimpleImputer(
    missing_values=np.nan,
    strategy="mean"                 
                     )
X[:,1:]=imputer.fit_transform(X[:,1:])

#Labeling categorical variables

from sklearn.preprocessing import LabelEncoder,OneHotEncoder
from sklearn.compose import ColumnTransformer

LEncoder=LabelEncoder()

Y=LEncoder.fit_transform(Y)

ct=ColumnTransformer(transformers=[("encoder",OneHotEncoder(),[0])],remainder="passthrough")

X=np.array(ct.fit_transform(X))

#Spliting data into training and testing dataset
from sklearn.model_selection import train_test_split

X_train,X_test,Y_train,Y_test=train_test_split(X,Y,test_size=0.2,random_state=1)

#Applying feature scaling to non categorical values
#using Standardization

from sklearn.preprocessing import StandardScaler

ss=StandardScaler()

X_train[:,3:]=ss.fit_transform(X_train[:,3:])
X_test[:,3:]=ss.fit_transform(X_test[:,3:])

#Data processing completed


