#define STRIP_MAX_SIZE 32
#define STRIPS_NUM 13
const uint16_t strips[13][32] = {
{512,513,514,515,516,517,518,519,520,521,522,523,524,525,526,527,528,529,530,531,532,533,534,535,536,537,538,539,540,541,542,543},
{544,545,546,547,548,549,550,551,552,553,554,555,556,557,558,559,560,561,562,563,564,565,566,567,568,569,570,571,572,SAFE_LED,SAFE_LED,SAFE_LED},
{573,574,575,576,577,578,579,580,581,582,583,584,585,586,587,588,589,590,591,592,593,594,595,596,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED},
{597,598,599,600,601,602,603,604,605,606,607,608,609,610,611,612,613,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED},
{614,615,616,617,618,619,620,621,622,623,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED},
{624,625,626,627,628,629,630,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED},
{631,632,633,634,635,636,637,638,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED},
{639,640,641,642,643,644,645,646,647,648,649,650,651,652,653,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED},
{654,655,656,657,658,659,660,661,662,663,664,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED},
{665,666,667,668,669,670,671,672,673,674,675,676,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED},
{677,678,679,680,681,682,683,684,685,686,687,688,689,690,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED},
{691,692,693,694,695,696,697,698,699,700,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED},
{701,702,703,704,705,706,707,708,709,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED,SAFE_LED},
};