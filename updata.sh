#!/bin/sh

LEWEIURL=http://www.lewei50.com/api/V1/gateway/UpdateSensors/01
USERKEY=
DATA=data.txt
./example
LINE=`head -1 $DATA`
curl --request POST $LEWEIURL --data "$LINE" --header "userkey:$USERKEY"