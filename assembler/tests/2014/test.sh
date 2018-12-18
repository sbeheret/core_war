if diff -q Asombra.s Kappa.s > /dev/null
then
  echo "The files are equal"
else
  echo "The files are different or inaccessible"
fi
