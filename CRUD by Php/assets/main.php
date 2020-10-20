<!-- main html file for CRUD (php version) -->
<?php echo $CRUD["MESSAGES"] ?><?php echo $CRUD["ERRORS"] ?>
<div class="form">
<form action="<?php echo $CRUD["SELF"] ?>" method="post" name="album">
    <p class="subheading"><?php echo $CRUD["FORM_HEAD"] ?></p>

    <table class="form">
    <tr>
        <td><p class="Afield"> Title:</p></td>
        <td><input class="Afield" type="text" name="Atitle" value="<?php echo $CRUD["Atitle"] ?>"> </td>
    </tr>
    <tr>
        <td><p class="Afield"> Artist:</p></td>
        <td><input class="Afield" type="text" name="Aartist" value="<?php echo $CRUD["Aartist"] ?>"> </td>
    </tr>
    <tr>
        <td><p class="Afield"> Label:</p></td>
        <td><input class="Afield" type="text" name="Alabel" value="<?php echo $CRUD["Alabel"] ?>"> </td>
    </tr>
    <tr class="released">
        <td><p class="Afield"> Released:</p></td>
        <td>
            Day <input class="day" type="text" name="Areleased_day" value="<?php echo $CRUD["Areleased_day"] ?>"> &nbsp;
            Month <?php album_month_select() ?> &nbsp;
            Year <input class="year" type="text" name="Areleased_year" value="<?php echo $CRUD["Areleased_year"] ?>"> &nbsp;
        </td>
    </tr>
    <tr class="buttons"><td colspan="2">
<p class="buttons">
<?php echo $CRUD["BUTTONS"] ?><?php echo $CRUD["HIDDENS"] ?>
</p>
    </td></tr>
    </table>


</form>
</div>
<?php echo $CRUD["PRECONTENT"] ?><?php echo $CRUD["CONTENT"] ?><?php echo $CRUD["POSTCONTENT"] ?>
