# gff_exporter
## This module provides the user to preliminary GFF which takes phylotree_consensus feature name as input in the url and displays following information
### Try example: http://<your-website>/test_gff/phytozome_10_2.59026947-consensus

1. GFF column 1: Source feature in this case phylotree consensus feature name
2. GFF column 2: source is empty '.' for now
3. GFF column 3: type is 'protein_hmm_match' in this case
4. GFF column 4 & 5: start and end are 'fmin' and 'fmax' values from featureloc table for the features that have source feature as column 1 
5. GFF column 6,7,8: is empty '.' for now
6. GFF column 9: protein domain feature name that is associated with the phylotree consensus feature from col 1
