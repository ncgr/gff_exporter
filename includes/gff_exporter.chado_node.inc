<?php

/** PEU
 * phylotree_domains
 *
 * Lookup for protein domains associated to the polypeptide in URL that belongs the this phylotree
 * use arguments ($name, $polypeptide)
*/
function phylotree_domains($phylo_cons_name)
{

 $sql = <<<SQL
 SELECT f.name, floc.fmin+1 as fmin ,floc.fmax+1 as fmax, c.name as feature_type from feature f
        INNER JOIN cvterm c on f.type_id=c.cvterm_id
        INNER JOIN featureloc floc on f.feature_id=floc.feature_id
        WHERE c.cvterm_id=(select cvterm_id from chado.cvterm where name='protein_hmm_match') AND floc.srcfeature_id IN (select feature_id from feature WHERE name = :phylo_cons_name)
SQL;

$args = array(':phylo_cons_name' => $phylo_cons_name);  
$result = chado_query($sql, $args);
header('Content-Type: text/plain');
foreach ($result as $r)
{
  echo "$phylo_cons_name\t.\t$r->feature_type\t$r->fmin\t$r->fmax\t.\t.\t.\tID=$r->name";
  echo "\r\n";
}
}
/**
$file = 'file.gff';

if (file_exists($file)) {
header('Content-Disposition: attachment; filename="'.basename($file).'"');
readfile($file);
exit;

}

}

#while ($row = $result->fetchField())
#{
#echo "name: $result->name fmin: $result->fmin fmax: $result->fmax \n";
#}
#} 


/*
$a = array();
$fmin = array();
$fmax = array();
foreach ($result as $r)
{
array_push($a, $r->name);
array_push($fmin, $r->fmin);
array_push($fmax, $r->fmax);
echo "$r->name $r->fmin $r->fmax \n";
}
*/
#$a = array();
#array_push($a, $output);

#foreach ($a as $ele) {
#    echo "$ele\n";
#}

#echo '<pre>';
#print_r($fmin);
#echo  '</pre>';

#print $output;
#return ($array);
#return $output;

 

/* write a SQL query to find protein domains of type protein_hmm_match given the name of phylotree_consensus feature like below


e.g. select name from feature where type_id='44794' and feature_id IN (select feature_id from featureloc where srcfeature_id ='3260858');
     Here feature_id 3260858 is phytozome_10_2.59026947-consensus

      name        
-------------------
 SM00129
 PF00225
 PF12711
 G3DSA:3.40.850.10
*/




#return 'Testing gff exporter, Hello!';

