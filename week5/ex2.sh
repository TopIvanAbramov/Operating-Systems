file="ex2.txt"

if ! [ -f "$file" ] #check if file not exists
then
    touch ex2.txt
    echo 0 >> ex2.txt
fi

if ln ex2.txt ex2.txt.lock
then
    for i in `seq 1 100`; do
        n=`tail -1 ex2.txt`
        n=$((n+1))
        echo "$n" >> ex2.txt
    done
    rm ex2.txt.lock
fi
