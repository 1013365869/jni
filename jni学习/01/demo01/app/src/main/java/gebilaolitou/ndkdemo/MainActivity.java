package gebilaolitou.ndkdemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        NDKTools ndkTools =new NDKTools();
        String text = ndkTools.getStringFromNDK();
        Log.i("gebilaolitou","text="+text);
    }
}
