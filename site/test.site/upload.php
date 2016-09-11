<?php
	require "./includes/db.php";

	$valid_types = array("gif","jpg", "png", "jpeg");

	if(isset($_FILES['ufile']) && $_FILES['ufile']['error'] != 4)
	{
		if ($_FILES['ufile']['error'] != 1 && $_FILES['ufile']['error'] != 0) {
		 	$error = $_FILES['ufile']['error'];
		 	$errors[] = 'Ошибка. Файл не загружен. Код ошибки: '. $error;
		}
		else
		{
			$path = 'images';
			$filename = $_FILES['ufile']['name'];
			$extension = strtolower(substr(strrchr($_FILES['ufile']['name'], '.'), 1));
			$type = $_FILES['ufile']['type'];
			$size = $_FILES['ufile']['size'];

			if(!in_array($extension, $valid_types))	exit;
			if($size > 2097152) exit;

			$filename = DFileHelper::getRandomFileName($path, $extension);
			$target = $path . '/' . $filename . '.' . $extension;
			move_uploaded_file($_FILES['ufile']['tmp_name'], $target);

			
		}

		$date = date("d:m:y");
		$user = R::findOne('users', "login = ?", array($_SESSION['logged_user']->login));
		$order = R::dispense('orders');
		$order->type_id = 1;
		$order->user_id = $user->id;
		$order->filename = $target;
		$order->order_status = 0;
		$order->filing_date = $date; 
		R::store($order);
		header("Location: my_orders.php");

	
	}
	
	class DFileHelper
{
    public static function getRandomFileName($path, $extension='')
    {
        $extension = $extension ? '.' . $extension : '';
        $path = $path ? $path . '/' : '';
 
        do {
            $name = md5(microtime() . rand(0, 9999));
            $file = $path . $name . $extension;
        } while (file_exists($file));
 
        return $name;
    }
}
?>