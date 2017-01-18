def recur(dimesion, i, k=arr[i + 1]의 dimesion에 포함여부):

if(i == num):
	if dimesion == numOfDimesion :


	return;

result = 
1) arr[i]를 포함할떄
result = arr[i] + recur(dimesion, i + 1, true);

2) arr[i]를 포함하지 않을때
if k == 1 :
	result = recur(dimesion + 1, i + 1, 0);
else k == 0:
	result = recur(dimesion, i + 1, 0);


