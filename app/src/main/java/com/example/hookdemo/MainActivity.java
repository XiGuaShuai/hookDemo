package com.example.hookdemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.example.hookdemo.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'hookdemo' library on application startup.
    static {
        System.loadLibrary("hookdemo");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        Button tv = binding.JNIMD5;
        tv.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Toast.makeText(MainActivity.this,   MD5("123456"), Toast.LENGTH_SHORT).show();
            }
        });



    }

    /**
     * A native method that is implemented by the 'hookdemo' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native String MD5(String s1);
}