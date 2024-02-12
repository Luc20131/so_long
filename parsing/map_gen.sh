#!/bin/bash

WIDTH=$1
HEIGHT=$2
NBR_COINS=$((RANDOM % ((($WIDTH - 2) * ($HEIGHT - 2) + 10) / 10) + 1))

rm map.ber
touch	map.ber
declare -A map

for ((y=0; y<$HEIGHT; y++))
do
	for ((x=0; x<$WIDTH; x++))
	do
		for ((z=0; z<2; z++))
		do
			if [ $z == 0 ]; then
				if [ $x == 0 ] || [ $x == $(($WIDTH - 1)) ]; then
					map[$y,$x,$z]=1
				else
					if [ $y == 0 ] || [ $y == $(($HEIGHT - 1)) ]; then
						map[$y,$x,$z]=1
					else
						rand=$((RANDOM% 100 + 1))
						if [ $rand -gt 70 ]; then
							map[$y,$x,$z]=1
						else
							map[$y,$x,$z]=0
						fi
					fi
				fi
			else
				map[$y,$x,$z]=0
			fi
		done
	done
done

echo $NBR_COINS
for ((i=0; i<$NBR_COINS; i++))
do
	while :
	do
		X_COINS=$((RANDOM % (($WIDTH - 2)) + 1))
		Y_COINS=$((RANDOM % (($HEIGHT - 2)) + 1))
		if [ map[$Y_COINS,$X_COINS,0] != C ] && [ map[] ]; then
			break
		fi
	done
	map[$Y_COINS,$X_COINS,0]=C
done

while :
do
	X_EXIT=$((RANDOM % (($WIDTH - 2)) + 1))
	Y_EXIT=$((RANDOM % (($HEIGHT - 2)) + 1))
	if [ map[$Y_EXIT,$X_EXIT,0] != C ]; then
			break
	fi
done
map[$Y_EXIT,$X_EXIT,0]=E

while :
do
	X_PERS=$((RANDOM % (($WIDTH - 2)) + 1))
	Y_PERS=$((RANDOM % (($HEIGHT - 2)) + 1))
	if [ map[$Y_EXIT,$X_EXIT,0] != C  ] && [ map[$Y_EXIT,$X_EXIT,0] != E ]; then
		break
	fi
done
map[$Y_PERS,$X_PERS,0]=P

for ((i=0; i<$HEIGHT; i++))
do
    for ((j=0; j<$WIDTH; j++))
    do
        printf "${map[$i,$j,0]}" >> map.ber
    done
	printf "\n" >> map.ber
done

