for a in [0-9]*.txt; do
   mv $a `printf %04d.%s ${a%.*} ${a##*.}`
done

