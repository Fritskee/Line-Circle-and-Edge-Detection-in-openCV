# Line-Circle-and-Edge-Detection-in-openCV
Line, circle and Edge Detection implemented in OpenFrameworks with the OpenCV library


In this repository, there are 3 folders. Each folder considers a different _shape_ detection algorithm.

1. Line Detection: Uses the "Canny Edge Detection" algorithm. An algorithm that has proven to work well for detecting lines. In the folder, a clip of a car driving has been included. When running the program you can see how the algorithm can detect the white lines on the road.
This could be a very naive approach to create a "line following" system. Eg. something that can be used in a factory floor where small autonomous robots follow a line on the floor to go from point A to point B.

2. Circle Detection: Uses "Hough Transform". It is a feature extraction method that shows great results for detecting circular objects. 

3. Edge Detection: In this folder you can find code that draws a dot on a detected edge. It will draw this in such a way that it will look like a continuous movement along the edge.
The method used here is again the "Canny Edge Detection". In the bin/data folder, you can find different _drawings_ that I made, consisting of a sawthoot, sinus and some other shapes. 
These shapes all have different forms, varying between straight and circular. This shows that Canny Edge Detection can detect edges in all sorts of forms.
