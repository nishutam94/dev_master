import pandas as pd
from sklearn.datasets import load_iris
iris_dataset = load_iris()
import numpy as np


'''
print(iris_dataset.keys())
print(iris_dataset["DESCR"][:1000])
print("data: {}".format(iris_dataset['data']))
print("target: {}".format(iris_dataset['target']))
print("target names: {}".format(iris_dataset['target_names']))
print("feature_names: {}".format(iris_dataset['feature_names']))
print("filename: {}".format(iris_dataset['filename']))
'''
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(iris_dataset['data'],iris_dataset['target'],random_state=0)

'''
print(X_train.shape)
print(X_test.shape)
print(y_train.shape)
print(y_test.shape)

'''

iris_dataframe = pd.DataFrame(X_train,columns=iris_dataset.feature_names)
#print(iris_dataframe)
#grr = pd.scatter_matrix(iris_dataframe, c=y_train, marker='o',hist_kwds={'bins':20},s=60, alpha =.8)
#print(grr)

from sklearn.neighbors import KNeighborsClassifier
knn = KNeighborsClassifier(n_neighbors = 1)
knn.fit(X_train,y_train)
print(knn)


X_new = np.array([[5, 3.9, 6, 0.2]])
print("X_new.shape: {}".format(X_new.shape))


prediction = knn.predict(X_new)
print("Prediction: {}".format(prediction))
print("Predicted target name: {}".format(
iris_dataset['target_names'][prediction]))


y_pred = knn.predict(X_test)
print("Test set predictions:\n {}".format(y_pred))

print(np.mean(y_pred == y_test))
print(knn.score(X_test, y_test))

