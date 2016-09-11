<?php
 require "./includes/db.php";

 $data = $_POST;

 if(isset($data['do_signup']))
 {
 	if (trim($data['login']) == '') 
 	{
 		$err[] = 'Введитее логин!';
 	}

 	if (trim($data['email']) == '') 
 	{
 		$err[] = 'Введитее email!';
 	}

 	if ($data['password'] == '') 
 	{
 		$err[] = 'Введите пароль!';
 	}

 	if ($data['password_2'] != $data['password']) 
 	{
 		$err[] = 'Пароли не совпадают!';
 	}

 	if (R::count('users', "login = ?", array($data['login'])) > 0) 
 	{
 		$err[] = 'Пользователь с таким именем уже существует!';
 	}

 	if (R::count('users', "email = ?", array($data['email'])) > 0) 
 	{
 		$err[] = 'Данный email уже используется!';
 	}

 	if (empty($err)) 
 	{
 		$user = R::dispense('users');
 		$user->login = $data['login'];
 		$user->email = $data['email'];
 		$user->password = password_hash($data['password'], PASSWORD_DEFAULT);
 		R::store($user);
 		echo '<div style="color: green;"> Вы успешно зарегистрированы!</div><hr>';

 	}
 	else
 	{
 		echo '<div style="color: red;">'.array_shift($err).'</div><hr>';
 	}
 }

?>


<form action="singup.php" method="POST">

<p>
	<p><strong>Ваш логин</strong>:</p>
	<input type="text" name="login"  value="<?php echo @$data['login'];?>" >
</p>

<p>
	<p><strong>Ваш Email</strong>:</p>
	<input type="email" name="email" value="<?php echo @$data['email']; ?>">
</p>

<p>
	<p><strong>Пароль</strong>:</p>
	<input type="password" name="password">
</p>

<p>
	<p><strong>Повторите пароль</strong>:</p>
	<input type="password" name="password_2">
</p>

<p>
	<input type="submit" value="submit" name="do_signup">
</p>



</form>