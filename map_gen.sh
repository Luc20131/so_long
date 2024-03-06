#!/bin/bash

WIDTH=$1
HEIGHT=$2
NBR_COINS=$((RANDOM % ((($WIDTH - 2) * ($HEIGHT - 2) + 10) / 10) + 1))

#!/bin/bash

# # Définition de la fonction neighbour_checker
# neighbour_checker() {
#     # Arguments: map, x, y

# 	map=$1
#     local x=$2
#     local y=$3
# 	printf "${map[$y,$x,1]}"

#     if [[ ${map[$y,$x,1]} == "A" || ${map[$y,$x,1]} == "P" ]]; then
#         if [[ ${map[$y][$x][1]} == 'A' ]]; then
#             map[$y][$x][1]='V'
#         fi
#         if [[ ${map[$y,$((x - 1)),1]} != '1' && ${map[$y,$((x - 1)),1]} != 'V' && ${map[$y,$((x - 1)),1]} != 'P' ]]; then
#             map[$y][$((x - 1))][1] ='A'
#         fi
#         if [[ map[$((y - 1))][$x][1] != '1' && map[$((y - 1))][$x][1] != 'V' && map[$((y - 1))][$x][1] != 'P' ]]; then
#             map[$((y - 1))][$x][1] ='A'
#         fi
#         if [[ map[$((y + 1))][$x][1] != '1' && map[$((y + 1))][$x][1] != 'V' && map[$((y + 1))][$x][1] != 'P' ]]; then
#             map[$((y + 1))][$x][1] ='A'
#         fi
#         if [[ ${map[$y][1]:$((x + 1)):1} != '1' && ${map[$y][1]:$((x + 1)):1} != 'V' && ${map[$y][1]:$((x + 1)):1} != 'P' ]]; then
#             map[$y][$((x + 1))][1] ='A'
#         fi
#     fi
#     if [[ map[$((y - 1))][$x][1] == 'A' ]]; then
#         neighbour_checker $map $x $((y - 1))
#     fi
#     if [[ map[$y][$((x + 1))][1] == 'A' ]]; then
#         neighbour_checker $map $((x + 1)) $y
#     fi
#     if [[ map[$((y + 1))][$x][1] == 'A' ]]; then
#         neighbour_checker $map $x $((y + 1))
#     fi
#     if [[ map[$y][$((x - 1))][1] == 'A' ]]; then
#         neighbour_checker $map $((x - 1)) $y
#     fi
# }

rm map.ber
touch	map.ber
declare -A map

for ((y=0; y<$HEIGHT; y++))
do
	for ((x=0; x<$WIDTH; x++))
	do
		if [ $x == 0 ] || [ $x == $(($WIDTH - 1)) ]; then
			map[$y,$x,0]=1
			map[$y,$x,1]=1
		else
			if [ $y == 0 ] || [ $y == $(($HEIGHT - 1)) ]; then
				map[$y,$x,1]=1
				map[$y,$x,0]=1
			else
				rand=$((RANDOM% 100 + 1))
				if [ $rand -gt 70 ]; then
					map[$y,$x,1]=1
					map[$y,$x,0]=1
				else
					map[$y,$x,1]=0
					map[$y,$x,0]=0
				fi
			fi
		fi
	done
done

echo $NBR_COINS
for ((i=0; i<$NBR_COINS; i++))
do
	while :
	do
		X_COINS=$((RANDOM % (($WIDTH - 2)) + 1))
		Y_COINS=$((RANDOM % (($HEIGHT - 2)) + 1))
		if [ map[$Y_COINS,$X_COINS,0] != C ]; then
			break
		fi
	done
	map[$Y_COINS,$X_COINS,0]=C
	map[$Y_COINS,$X_COINS,1]=C
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
map[$Y_EXIT,$X_EXIT,1]=E

while :
do
	X_PERS=$((RANDOM % (($WIDTH - 2)) + 1))
	Y_PERS=$((RANDOM % (($HEIGHT - 2)) + 1))
	if [ map[$Y_EXIT,$X_EXIT,0] != C  ] && [ map[$Y_EXIT,$X_EXIT,0] != E ]; then
		break
	fi
done
map[$Y_PERS,$X_PERS,0]=P
map[$Y_PERS,$X_PERS,1]=P

neighbour_checker $map $X_PERS $Y_PERS

for ((i=0; i<$HEIGHT; i++))
do
    for ((j=0; j<$WIDTH; j++))
    do
        printf "${map[$i,$j,1]}"
    done
	printf "\n"
done

printf "\n"

for ((i=0; i<$HEIGHT; i++))
do
    for ((j=0; j<$WIDTH; j++))
    do
        printf "${map[$i,$j,0]}" >> map.ber
    done
	printf "\n" >> map.ber
done
