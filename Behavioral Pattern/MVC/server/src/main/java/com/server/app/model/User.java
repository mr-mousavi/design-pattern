package com.server.app.model;

import lombok.Data;
import org.microdeaf.hbm.model.BaseEntity;
import javax.persistence.*;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Size;


@Data
@Entity
@Table(name = "sa_user")
public class User extends BaseEntity<Long> {

    @NotNull(message = "{validation.user.name.notNull}")
    @Size(min = 1, message = "{validation.user.name.size}")
    @Column(name = "name")
    private String name;

    @NotNull(message = "{validation.user.username.notNull}")
    @Size(min = 1, message = "{validation.user.username.size}")
    @Column(name = "username", unique=true)
    private String username;

//    @NotNull(message = "{validation.user.authKey.notNull}")
//    @Size(min = 1, message = "{validation.user.authKey.size}")
    @Column(name = "authKey")
    private String authKey;

    @NotNull(message = "{validation.user.password.notNull}")
    @Size(min = 1, message = "{validation.user.password.size}")
    @Column(name = "password")
    private String password;

    @NotNull(message = "{validation.user.status.notNull}")
    @Column(name = "status")
    private Integer status;

//    @Transient
//    private List<Role> roles;

}
