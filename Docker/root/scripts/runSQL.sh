#!/bin/bash
NOW=$(date +"%Y-%m-%d-%H:%I:%S")
echo "DATE: $NOW"

STRINGS=(
  "10.176.187.80;siga_eadbsp_funcional;5432;sistemas;123456"
  "10.176.187.80;siga_eadfad_funcional;5432;sistemas;123456"
  "10.176.187.80;siga_eadfmu_funcional;5432;sistemas;123456"
  "10.176.187.80;siga_eadfpb_funcional;5432;sistemas;123456"
  "10.176.187.80;siga_eadibm_funcional;5432;sistemas;123456"
  "10.176.187.80;siga_eaduam_funcional;5432;sistemas;123456"
  "10.176.187.80;siga_eadufg_funcional;5432;sistemas;123456"
  "10.176.187.80;siga_eadunf_funcional;5432;sistemas;123456"
  "10.176.187.80;siga_eadunp_funcional;5432;sistemas;123456"
  "10.176.187.80;siga_eadunr_funcional;5432;sistemas;123456"
)
#  "10.176.187.14;siga_eadfad_dev;5432;sistemas;123456"
#  "10.176.187.14;siga_eadfmu_dev;5432;sistemas;123456"
#  "10.176.187.14;siga_eaduam_dev;5432;sistemas;123456"
#  "10.176.187.14;siga_eadunf_dev;5432;sistemas;123456"
#  "10.176.187.14;siga_eadunp_dev;5432;sistemas;123456"

for STR in ${STRINGS[*]}; do
    IFS=';' read -ra ARRAY <<< "$STR"
    echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
    echo "HOST: ${ARRAY[0]}"
    echo "PORT: ${ARRAY[2]}"
    echo "DB:   ${ARRAY[1]}"
#    PGPASSWORD="${ARRAY[4]}" psql -a -f $1 -h "${ARRAY[0]}" -p "${ARRAY[2]}" -U "${ARRAY[3]}" "${ARRAY[1]}" -o "TXTOUT_${ARRAY[1]}.txt"
    PGPASSWORD="${ARRAY[4]}" psql -a -f $1 -h "${ARRAY[0]}" -p "${ARRAY[2]}" -U "${ARRAY[3]}" "${ARRAY[1]}" -t -A -F";" -o "./out/CSVOUT_${ARRAY[1]}.csv"
    echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
done
