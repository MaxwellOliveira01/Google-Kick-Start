for j in 1...100
do
    python3 create.py > case
    ./brute < case > bruteout
    ./cod < case > codout
    diff codout bruteout
done