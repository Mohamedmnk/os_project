<!DOCTYPE>
<head>
<title><center> PHP calculate Elecricity Bill </center></title>
</head>
<?php
$result_str = $result = '';
if (isset($_POST['unit-submit']))
{
$units = $_POST['units'];
if (!empty($units))
{
$result = calculate_bill($units);
$result_str = 'total amount of ' .$units.'-' . $result;
}
}
function calculate_bill($units)
{
$first_fifty_unit=9;
$second_fifth_unit=12;
$third_fifth_unit=15;
if($units <=50)
{
$bill=$units * $fisrt_fifth_unit;
}
else if($unit >50 && $unit<=100)
{
$temp = 50*$first_fifth_unit;
$remaining_units = $units - 50;
$bill = $temp+($remaining_units * second_fifth_unit);
}
else if ($units > 100 && $units<=150)
{
$temp = (50 * 9) + (100 * $second_fifth_unit);
$remaining_units = $units - 150;
$bill = $temp + ($remaining_units * third_fifth_unit);
}
return number_format((float)$bill,2,'.','');
}
?>
<body>
<div id="page-wrap">
<h1>php-calculate elecricity bill</h1>
<form action="" method="post" id="bill-form">
<input type="number" name="units" id="units" placeholder="please enter the number of the units"/>
<input type="submit" name="unit-submit" id=unit-submit value="submit"/>
</form>
<div>
<?php echo '<br/>'. $result_str; ?>
</div>
</div>
</body>
</html>

