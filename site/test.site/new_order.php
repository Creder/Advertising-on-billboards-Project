<?php 
    require "./includes/db.php";

?>



<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
   
    <title>Agadver</title>

    <link href="css/bootstrap.css" rel="stylesheet">
    <link href="css/style.css" rel="stylesheet">
  </head>
  <body>

  <div class="navbar navbar-default navbar-static-top">
    	<div class="container">
    		<div class="navbar-header">
    			
    			<button type="button" class="navbar-toggle" data-toggle ="collapse" data-target="#responsive-menu">
    				<span class="sr-only">Открыть навигацию</span>
    				<span class="icon-bar"></span>
    				<span class="icon-bar"></span>
    				<span class="icon-bar"></span>
    			</button>
    			<a class="navbar-brand" href="/">Agadver</a>
    		</div>
    		<div class="collapse navbar-collapse" id="responsive-menu">
    			<ul class="nav navbar-nav">
    				<li><a href="#">О нас</a></li>
    				<li><a href="#">Контакты</a></li>
    				<li><a href="#">Наши проекты</a></li>
    				<li><a href="#">Цены и услуги</a></li>
    				<li><a href="#">Карта биллбордов</a></li>
    			</ul>
    		</div>
    	</div>
    </div>

    


    <div class="menu"> <p>Меню</p>

     		<?php if(isset($_SESSION['logged_user'])) :?>
				<p>Вы авторизованы, как <?php echo $_SESSION['logged_user']->login; ?></p>
				<ul class="user-nav">
    				<li><a href="#">Мой профиль</a></li>
    				<li><a href="my_orders.php">Мои заказы</a></li>
    				<li><a href="logout.php"> Выйти</a></li>
    			</ul>
				
			<?php else :header("Location: /login.php"); ?>
				
				
			<?php endif; ?>
    </div>

    <div class="content"> 
        <p>
            Тип заказа
        </p>

        <p>
            
        </p>
        <form action="upload.php" method="post" enctype="multipart/form-data">
            <input type="file" name="ufile"/>
            <input type="submit" value="upload_file"/>
        </form>
    </div>

  


   
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.mini.js"></script>

    <script src="js/bootstrap.js"></script>
  </body>
</html>