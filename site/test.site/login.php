<?php
	require "./includes/db.php";

	$data =$_POST;



	
	if(isset($data['do_login']))
	{

		if (trim($data['login']) == '') 
 		{
 			$err[] = 'Введитее логин!';
 		}

 		if (trim($data['password']) == '') 
 		{
 			$err[] = 'Введитее пароль!';
 		}

		$user = R::findOne('users', "login = ?", array($data['login']));

		if($user)
		{
			if(password_verify($data['password'], $user->password))
			{
				$_SESSION['logged_user'] = $user;
				header("Location: /");
			}
			else
			{
				$err[] = 'Неверный логин или пароль!';
			}
		}
		else
		{
			$err[] = 'Неверный логин или пароль!';
		}

		if(empty($err))
		{
			
		}
		else
		{
			echo '<div style="color: red;">'.array_shift($err).'</div><hr>';
		}

	}


?>

<form action="login.php" method="POST">
<p>
	<p><strong>Логин</strong>:</p>
	<input type="text" name="login">
</p>

<p>
	<p><strong>Пароль</strong>:</p>
	<input type="password" name="password">
</p>

<p>
	<input type="submit" value="submit" name="do_login">
</p>
</form>
